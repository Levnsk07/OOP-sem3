cmake_minimum_required(VERSION 3.12)
project(Main LANGUAGES CXX)


add_subdirectory(addLib)  # add Lib

add_executable(main_app main.cpp) # make main file

target_link_libraries(main_app PRIVATE my_add_lib) # link librale
