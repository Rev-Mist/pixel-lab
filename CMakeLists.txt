
cmake_minimum_required(VERSION 3.24)

project(PixelLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

add_executable(pixel_lab
    src/main.cpp
 "src/Player.h" "src/Player.cpp" "src/Coin.h" "src/Coin.cpp")

target_link_libraries(pixel_lab PRIVATE SDL3::SDL3)
