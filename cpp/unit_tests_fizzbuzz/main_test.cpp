// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"


TEST(FizzBuzzTest, Fizz) {
   string result = FizzBuzz(3);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, Buzz) {
   string result = FizzBuzz(5);
   EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTest, FizzBuzz) {
   string result = FizzBuzz(15);
   EXPECT_EQ(result, "FizzBuzz");
}


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

