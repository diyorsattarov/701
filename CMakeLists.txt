cmake_minimum_required(VERSION 3.2)

project(cpp-stream-record VERSION 0.01)

# Option to build either "src" or "test"
option(BUILD_SRC "Build the src target" ON)
option(BUILD_TEST "Build the test target" OFF)

# Add the "src" subdirectory if BUILD_SRC is enabled
if(BUILD_SRC)
    add_subdirectory(src)
endif()

# Add the "test" subdirectory if BUILD_TEST is enabled
if(BUILD_TEST)
    add_subdirectory(test)
endif()

# Clean targets
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMENT "Cleaning build files in root directory"
)

# Dependencies for clean_all
if(BUILD_SRC)
    add_dependencies(clean_all clean_src)
endif()

if(BUILD_TEST)
    add_dependencies(clean_all clean_test)
endif()
