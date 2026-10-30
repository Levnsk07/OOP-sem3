cmake_minimum_required(VERSION 3.15)
project(WordProcessor CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libWordWrap)

add_executable(WordProcessorMain main.cpp)

target_link_libraries(WordProcessorMain PRIVATE libWordWrap)
