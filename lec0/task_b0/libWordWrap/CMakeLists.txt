add_subdirectory(libWordMap)

add_library(libWordWrap STATIC
        WordWrap.cpp
        WordWrap.h
)

# Указываем, где искать заголовки этой библиотеки (в текущей папке ".")
target_include_directories(libWordWrap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Связываем libWordWrap с libWordMap
target_link_libraries(libWordWrap PUBLIC libWordMap)
