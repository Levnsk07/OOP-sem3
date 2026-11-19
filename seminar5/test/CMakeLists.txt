add_executable(runTests
        test_add.cpp
)

target_link_libraries(runTests PRIVATE
        my_add_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(runTests)
