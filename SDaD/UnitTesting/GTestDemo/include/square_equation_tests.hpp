#include <gtest/gtest.h>
#include "square_equation.hpp"

TEST(SquareEquationTests, roots_count__HasNoRoots__ReturnsZero) {
    ASSERT_EQ(0, roots_count(1, 0, 2));
}
TEST(SquareEquationTests, roots_count__HasNoRootsOther__ReturnsZero) {
    ASSERT_EQ(0, roots_count(-3, 3, -7));
}

TEST(SquareEquationTests, roots_count__OneRoot__ReturnsOne) {
    ASSERT_EQ(1, roots_count(4, -12, 9));
}
TEST(SquareEquationTests, roots_count__OneRootOther__ReturnsOne) {
    ASSERT_EQ(1, roots_count(1, 4, 4));
}

TEST(SquareEquationTests, roots_count__TwoRoots__ReturnsTwo) {
    ASSERT_EQ(2, roots_count(-3, 18, 4));
}
TEST(SquareEquationTests, roots_count__TwoRootsOther__ReturnsTwo) {
    ASSERT_EQ(2, roots_count(1, 0, -5));
}
