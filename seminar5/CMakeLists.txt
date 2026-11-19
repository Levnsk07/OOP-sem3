cmake_minimum_required(VERSION 3.15)
project(WordProcessor CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(addLib)

add_executable(WordProcessor main.cpp)

target_link_libraries(WordProcessor PRIVATE my_add_lib)


#==============
if(BUILD_TESTS)

    message(STATUS "Сборка тестов включена")
    enable_testing()
    add_subdirectory(test)

endif ()