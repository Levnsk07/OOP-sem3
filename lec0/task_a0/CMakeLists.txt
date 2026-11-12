
cmake_minimum_required(VERSION 3.15)
project(WordProcessor CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(lib_module1)
add_subdirectory(lib_module2)


add_executable(main main.cpp)


target_link_libraries(main PRIVATE lib_module1)
target_link_libraries(main PRIVATE lib_module2)
