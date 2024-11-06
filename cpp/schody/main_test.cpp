#include <gtest/gtest.h>
#include "functions.cpp"

TEST(calculate_stairs, schody0) {
    StairsResult wynik = calculate_stairs(100, 140);
    StairsResult oczekiwany = {5, 16.67, 27.99};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody1) {
    StairsResult wynik = calculate_stairs(100, 150);
    StairsResult oczekiwany = {6, 16, 25};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody2) {
    StairsResult wynik = calculate_stairs(190, 250);
    StairsResult oczekiwany = {10, 17.28, 25.00};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody3) {
    StairsResult wynik = calculate_stairs(200, 280);
    StairsResult oczekiwany = {11, 16.67, 25.45};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody4) {
    StairsResult wynik = calculate_stairs(200, 300);
    StairsResult oczekiwany = {12, 16, 25};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schody5) {
    StairsResult wynik = calculate_stairs(380, 500);
    StairsResult oczekiwany = {20, 18.1, 25};
    EXPECT_EQ(wynik, oczekiwany);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

