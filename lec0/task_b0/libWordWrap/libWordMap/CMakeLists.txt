
add_library(libWordMap STATIC WordMap.cpp) # TODO add header

target_include_directories(libWordMap INTERFACE .)
