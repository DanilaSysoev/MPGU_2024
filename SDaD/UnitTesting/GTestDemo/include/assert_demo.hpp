#include <gtest/gtest.h>

TEST(AssertDemo, demo_true) {
    ASSERT_TRUE(true);
}
TEST(AssertDemo, demo_false) {
    ASSERT_FALSE(false);
}

TEST(AssertDemo, demo_eq) {
    ASSERT_EQ(5, 5);
}
TEST(AssertDemo, demo_ne) {
    ASSERT_NE(5, 6);
}
TEST(AssertDemo, demo_lt) {
    ASSERT_LT(5, 7);
}
TEST(AssertDemo, demo_le) {
    ASSERT_LE(5, 5);
}
TEST(AssertDemo, demo_gt) {
    ASSERT_GT(7, 5);
}
TEST(AssertDemo, demo_ge) {
    ASSERT_LE(5, 5);
}


TEST(AssertDemo, demo_streq) {
    ASSERT_STREQ("5", "5");
}
TEST(AssertDemo, demo_strne) {
    ASSERT_STRNE("5", "23");
}
TEST(AssertDemo, demo_strcaseeq) {
    ASSERT_STRCASEEQ("asd", "Asd");
}
TEST(AssertDemo, demo_strcasene) {
    ASSERT_STRCASENE("asd", "Asfd");
}


TEST(AssertDemo, demo_float_eq) {
    ASSERT_FLOAT_EQ(2.4f, 2.400000001f);
}
TEST(AssertDemo, demo_double_eq) {
    ASSERT_DOUBLE_EQ(2.4, 2.40000000000000001);
}
TEST(AssertDemo, demo_near) {
    ASSERT_NEAR(2.4, 2.401, 0.01);
}
