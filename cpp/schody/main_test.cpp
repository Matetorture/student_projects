// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(calculate_stairs, schodyMozliwe0) {
    StairsResult wynik = calculate_stairs(180, 500);
    EXPECT_EQ(wynik, {9, 20.0, 55.55, true, "Sukces"});
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

