#include <gtest/gtest.h>
#include "functions.cpp"

TEST(calculate_stairs, schody0) {
    StairsResult wynik = calculate_stairs(100, 140);
    StairsResult oczekiwany = {5, 17, 28};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody1) {
    StairsResult wynik = calculate_stairs(100, 150);
    StairsResult oczekiwany = {6, 16, 25};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody2) {
    StairsResult wynik = calculate_stairs(190, 250);
    StairsResult oczekiwany = {10, 18, 25};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody3) {
    StairsResult wynik = calculate_stairs(200, 280);
    StairsResult oczekiwany = {10, 19, 28};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody4) {
    StairsResult wynik = calculate_stairs(200, 300);
    StairsResult oczekiwany = {12, 16, 25};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody5) {
    StairsResult wynik = calculate_stairs(380, 500);
    StairsResult oczekiwany = {20, 19, 25};
    EXPECT_EQ(wynik, oczekiwany);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

