

add_library(my_add_lib STATIC Add.cpp Add.h)

target_include_directories(my_add_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
