#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <boost/beast/ssl.hpp>
#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <fstream> // Added for reading the config file

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
namespace ssl = boost::asio::ssl;
using tcp = boost::asio::ip::tcp;

// Function to read the client secret from config.json
std::string ReadClientSecretFromConfig() {
    std::ifstream config_file("config.json");
    nlohmann::json config_json;
    
    if (config_file.is_open()) {
        try {
            config_file >> config_json;
        } catch (const std::exception& ex) {
            spdlog::error("Failed to parse configuration file: {}", ex.what());
            return "";
        }
    } else {
        spdlog::error("Failed to open configuration file.");
        return "";
    }

    std::string client_secret = config_json.value("client_secret", "");
    if (client_secret.empty()) {
        spdlog::error("Client secret not found in the configuration file.");
    }

    return client_secret;
}


// Base fixture with common setup and teardown
class BaseTestFixture : public ::testing::Test {
protected:
    BaseTestFixture() : io_context(), ssl_context(ssl::context::sslv23) {
        ssl_context.set_default_verify_paths();
        spdlog::info("Welcome to spdlog!");
    }

    asio::io_context io_context;
    ssl::context ssl_context;
};

// Derived fixture for specific test cases
class MyTestFixture : public BaseTestFixture {
};

TEST_F(MyTestFixture, TestIsUserLive) {
    // Read the client secret from config.json
    std::string client_secret = ReadClientSecretFromConfig();
    if (client_secret.empty()) {
        spdlog::error("Client secret not found. Exiting.");
        return;
    }

    // Create a resolver for the token endpoint
    tcp::resolver token_resolver(io_context);
    tcp::resolver::results_type token_endpoints = token_resolver.resolve("id.twitch.tv", "https");
    ssl::stream<tcp::socket> token_socket(io_context, ssl_context);

    // Connect to the token endpoint
    boost::asio::connect(token_socket.next_layer(), token_endpoints.begin(), token_endpoints.end());
    token_socket.handshake(ssl::stream_base::client);

    // Obtain an access token using client credentials
    http::request<http::string_body> token_request{http::verb::post, "/oauth2/token", 11};
    token_request.set(http::field::host, "id.twitch.tv");
    token_request.set(http::field::content_type, "application/x-www-form-urlencoded");
    std::string client_id = "idebams24qkagk5c7psd0wtsgxa5nx";

    // Use the extracted client_secret
    token_request.body() = "client_id=" + client_id + "&client_secret=" + client_secret + "&grant_type=client_credentials";
    token_request.prepare_payload();

    http::write(token_socket, token_request);

    beast::flat_buffer token_buffer;
    http::response<http::dynamic_body> token_response;
    http::read(token_socket, token_buffer, token_response);

    spdlog::info("Token Response status code: {}", token_response.result_int());
    spdlog::info("Token Response body: {}", beast::buffers_to_string(token_response.body().data()));
    EXPECT_EQ(token_response.result(), http::status::ok);
    nlohmann::json token_json_response = nlohmann::json::parse(beast::buffers_to_string(token_response.body().data()));

    // Extract the "access_token" from the token JSON response
    std::string access_token = token_json_response["access_token"];

    spdlog::info("Access token: {}", access_token);

    // Create a resolver for the API endpoint
    tcp::resolver api_resolver(io_context);
    tcp::resolver::results_type api_endpoints = api_resolver.resolve("api.twitch.tv", "https");
    ssl::stream<tcp::socket> api_socket(io_context, ssl_context);

    // Connect to the API endpoint
    boost::asio::connect(api_socket.next_layer(), api_endpoints.begin(), api_endpoints.end());
    api_socket.handshake(ssl::stream_base::client);

    // Construct the HTTP GET request to check if a specific user is live
    std::string userLogin = "agurin"; // Replace with the user's login
    http::request<http::string_body> req{http::verb::get, "/helix/streams?user_login=" + userLogin, 11};
    req.set(http::field::host, "api.twitch.tv");
    req.set(http::field::authorization, "Bearer " + access_token); // Use "Bearer" prefix
    req.set(http::field::content_type, "application/json");
    req.set("Client-ID", client_id);
    // Send the HTTP request to the API endpoint
    http::write(api_socket, req);

    // Read the HTTP response from the API
    beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    http::read(api_socket, buffer, res);

    spdlog::info("Response status code: {}", res.result_int());
    spdlog::info("Response body: {}", beast::buffers_to_string(res.body().data()));

    // Check if the user is live by parsing the JSON response
    if (res.result() == http::status::ok) {
        nlohmann::json json_response;
        try {
            json_response = nlohmann::json::parse(beast::buffers_to_string(res.body().data()));
        } catch (const std::exception& ex) {
            spdlog::error("Failed to parse JSON response: {}", ex.what());
            return;
        }

        auto streams = json_response["data"];

        if (!streams.empty() && streams.is_array()) {
            // The user is live
            spdlog::info("User is live!");

            // Start FFmpeg screen recording
            std::string outputFileName = "stream_record.mp4"; // Set your desired output file name
            int recordingDuration = 10; // Recording duration in seconds

            // Construct the FFmpeg command to start recording
            std::string ffmpegCommand = "ffmpeg -f gdigrab -r 60 -s 1920x1080 -i desktop -t " + std::to_string(recordingDuration) + " " + outputFileName;

            // Execute the FFmpeg command
            int ffmpegExitCode = std::system(ffmpegCommand.c_str());

            if (ffmpegExitCode == 0) {
                spdlog::info("Recording completed successfully.");
            } else {
                spdlog::error("Failed to record the stream.");
            }
        } else {
            spdlog::info("User is not live.");
        }
    } else {
        spdlog::error("Failed to retrieve stream information. Status code: {}", res.result_int());
    }

    // Add your assertions here based on the test scenario
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
