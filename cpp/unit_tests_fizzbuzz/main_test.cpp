// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"


TEST(mojagrupatestow, mojtest) {
   string reult = FizzBuzz(3);
   EXPECT_EQ(FizzBuzz, "Fizz");
}

TEST(mojagrupatestow, mojtest) {
   string reult = FizzBuzz(5);
   EXPECT_EQ(FizzBuzz, "Fizz");
}

TEST(mojagrupatestow, mojtest) {
   string reult = FizzBuzz(15);
   EXPECT_EQ(FizzBuzz, "FizzBuzz");
}


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

