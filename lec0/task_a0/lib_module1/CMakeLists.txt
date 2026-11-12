

add_library(lib_module1 STATIC
        module1.cpp
        module1.h
)

target_include_directories(lib_module1 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
