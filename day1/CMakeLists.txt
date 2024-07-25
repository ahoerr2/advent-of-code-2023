cmake_minimum_required(VERSION 3.20)
project(advent-of-code VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the path to Clang
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

# Set output directory

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

# Add include directories
include_directories(include)

# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Link against libc++
target_link_libraries(${PROJECT_NAME} PRIVATE c++)