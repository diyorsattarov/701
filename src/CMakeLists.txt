cmake_minimum_required(VERSION 3.0)

project(src)

set(CMAKE_CXX_STANDARD 11)  # Set your desired C++ standard here
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_SOURCE_DIR}/extern/json")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)

add_executable(main
	main.cpp
)

find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)
find_package(spdlog REQUIRED)
find_package(nlohmann_json)
target_include_directories(main PRIVATE
    ${Boost_INCLUDE_DIRS}  # Include directories for Boost
    ${OPENSSL_INCLUDE_DIR}  # Include directories for OpenSSL
    ${SPDLOG_INCLUDE_DIRS}  # Include directories for spdlog
)

target_link_libraries(main PRIVATE
	Boost::system 
	OpenSSL::SSL 
	OpenSSL::Crypto
	ws2_32
	spdlog::spdlog
    nlohmann_json::nlohmann_json
)

add_custom_target(clean_src
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/build
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/src/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/src/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/src/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/src/cmake_install.cmake
	COMMENT "Cleaning build files"
)
