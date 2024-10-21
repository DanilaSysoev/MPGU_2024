#include <gtest/gtest.h>
#include "ArrayExtension.hpp"

TEST(ArrayExtensionsTests, error_1) {
    ArrayExtension ext({1, 2, 3, 4});
    ASSERT_EQ(1, ext.min());
}
TEST(ArrayExtensionsTests, error_2) {
    ArrayExtension ext({1, 2, 3, 4});
    ASSERT_EQ(4, ext.max());
}

TEST(ArrayExtensionsTests, error_3) {
    ArrayExtension ext({1, 2, 3, 4});
    ASSERT_EQ(10, ext.sum());
}
TEST(ArrayExtensionsTests, error_4) {
    ArrayExtension ext({1, 2, 3, 4});
    ASSERT_NEAR(2.5f, ext.mean(), 0.001f);
}

TEST(ArrayExtensionsTests, error_5) {
    ArrayExtension ext({1, 2, 3, 4});
    ASSERT_NEAR(2.5f, ext.median(), 0.001f);
}
