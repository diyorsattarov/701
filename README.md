markdown

# Twitch Chat Bot in C++

This is a simple Twitch chat bot written in C++ that interacts with the Twitch chat using the Twitch IRC protocol. The bot is designed to join a specified Twitch channel and respond to commands from viewers.

## Features

- Join Twitch chat channel and listen for messages.
- Respond to specific commands from viewers.
- Customizable command handling and response logic.

## Prerequisites

Before you begin, ensure you have met the following requirements:

- CMake (minimum version 3.2)
- C++ compiler (supporting C++11 or later)
- Boost/Beast
- spdlog
- googletest
- nholmman/json
## Getting Started
```
git clone https://github.com/diyooor/cpp-chatbot
cmake .
cmake --build .
./test/bin/test_main.exe
```
## Testing
```
admin at ~/workspace/scratch/cpp-stream-record $ ./test/bin/test_main.exe
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from MyTestFixture
[ RUN      ] MyTestFixture.TestIsUserLive
[2023-09-07 20:23:00.550] [info] Welcome to spdlog!
[2023-09-07 20:23:01.086] [info] Token Response status code: 200
[2023-09-07 20:23:01.086] [info] Token Response body: {"access_token":"xwlpfs6a87a665dvyspo0y4iith4cj","expires_in":5546578,"token_type":"bearer"} 

[2023-09-07 20:23:01.087] [info] Access token: xwlpfs6a87a665dvyspo0y4iith4cj
[2023-09-07 20:23:01.286] [info] Response status code: 200
[2023-09-07 20:23:01.286] [info] Response body: {"data":[{"id":"49256531373","user_id":"51496027","user_login":"loltyler1","user_name":"loltyler1","game_id":"21779","game_name":"League of Legends","type":"live","title":"SPIN FASTEST ! hehe so FUN ! GO MORED ! wee feel wind through HAIR and enjoy :D play over . BACK FOCUSED . DOMINATION INCOME !!!! WOOT","viewer_count":13258,"started_at":"2023-09-07T20:29:50Z","language":"en","thumbnail_url":"https://static-cdn.jtvnw.net/previews-ttv/live_user_loltyler1-{width}x{height}.jpg","tag_ids":[],"tags":["English"],"is_mature":false}],"pagination":{"cursor":"eyJiIjp7IkN1cnNvciI6ImV5SnpJam94TXpJMU9DNHhOVFUxT1RRd016Y3hPRFFzSW1RaU9tWmhiSE5sTENKMElqcDBjblZsZlE9PSJ9LCJhIjp7IkN1cnNvciI6IiJ9fQ"}}
[2023-09-07 20:23:01.287] [info] User is live!
[       OK ] MyTestFixture.TestIsUserLive (887 ms)
[----------] 1 test from MyTestFixture (893 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (909 ms total)
[  PASSED  ] 1 test.

```

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to create a pull request.
License

This project is licensed under the MIT License. See the LICENSE file for details.