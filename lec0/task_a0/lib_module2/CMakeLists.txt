

add_library(lib_module2 STATIC
        module2.cpp
        module2.h
)

target_include_directories(lib_module2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
