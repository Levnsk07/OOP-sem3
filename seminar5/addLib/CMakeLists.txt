cmake_minimum_required(VERSION 3.15)
project(WordProcessor CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_library(my_add_lib INTERFACE)
target_include_directories(my_add_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
