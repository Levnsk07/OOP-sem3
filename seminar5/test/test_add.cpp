

#include "Add.h"
#include <gtest/gtest.h>

TEST(add, add) {
    ASSERT_EQ(Add::addTemplate(1, 1), 2);
}
TEST(add, add_wrong) {
    ASSERT_EQ(Wrong::addTemplate(1, 1), 2);
}
TEST(add, add_random) {
    EXPECT_GT (randAdd::addTemplate(1), 0);
}