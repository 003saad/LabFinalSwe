#include<stdio.h>
#include<gtest/gtest.h>

using namespace std;

TEST(ExampleTest, Test1) {
    EXPECT_EQ(1, 1);
}
TEST(ExampleTest, Test2) {
    EXPECT_EQ(2, 2);
}
TEST(ExampleTest, Test3) {
    EXPECT_EQ(3, 3);
}
TEST(ExampleTest, Test4) {
    EXPECT_EQ(4, 4);
}
TEST(ExampleTest, Test5) {
    EXPECT_EQ(5, 5);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}