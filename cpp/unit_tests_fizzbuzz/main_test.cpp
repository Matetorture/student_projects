// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(FizzBuzzTest, FizzBuzz1) {
   string result = FizzBuzz(1);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz2) {
   string result = FizzBuzz(2);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz3) {
   string result = FizzBuzz(3);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz4) {
   string result = FizzBuzz(4);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz5) {
   string result = FizzBuzz(5);
   EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTest, FizzBuzz6) {
   string result = FizzBuzz(6);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz7) {
   string result = FizzBuzz(7);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz8) {
   string result = FizzBuzz(8);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz9) {
   string result = FizzBuzz(9);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz10) {
   string result = FizzBuzz(10);
   EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTest, FizzBuzz11) {
   string result = FizzBuzz(11);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz12) {
   string result = FizzBuzz(12);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz13) {
   string result = FizzBuzz(13);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz14) {
   string result = FizzBuzz(14);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz15) {
   string result = FizzBuzz(15);
   EXPECT_EQ(result, "FizzBuzz");
}

TEST(FizzBuzzTest, FizzBuzz16) {
   string result = FizzBuzz(16);
   EXPECT_EQ(result, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

