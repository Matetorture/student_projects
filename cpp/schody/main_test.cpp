#include <gtest/gtest.h>
#include "functions.cpp"

TEST(calculate_stairs, schody0) {
    StairsResult wynik = calculate_stairs(85, 135);
    StairsResult oczekiwany = {5, 17, 27};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody1) {
    StairsResult wynik = calculate_stairs(170, 270);
    StairsResult oczekiwany = {10, 17, 27};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody2) {
    StairsResult wynik = calculate_stairs(72, 120);
    StairsResult oczekiwany = {4, 18, 30};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody3) {
    StairsResult wynik = calculate_stairs(144, 240);
    StairsResult oczekiwany = {8, 18, 30};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody4) {
    StairsResult wynik = calculate_stairs(105, 189);
    StairsResult oczekiwany = {6, 17.5, 31.5};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody5) {
    StairsResult wynik = calculate_stairs(72, 100);
    StairsResult oczekiwany = {4, 18, 25};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody6) {
    StairsResult wynik = calculate_stairs(756, 1292.5);
    StairsResult oczekiwany = {45, 16.8, 28.72};
    EXPECT_EQ(wynik, oczekiwany);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

