// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"

//możliwe
TEST(calculate_stairs, schodyMozliwe0) {
    StairsResult wynik = calculate_stairs(180, 500);
    StairsResult oczekiwany = {10, 18, 50, true, "Sukces"};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schodyMozliwe1) {
    StairsResult wynik = calculate_stairs(152, 400);
    StairsResult oczekiwany = {8, 19, 50, true, "Sukces"};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schodyMozliwe2) {
    StairsResult wynik = calculate_stairs(95, 300);
    StairsResult oczekiwany = {5, 19, 60, true, "Sukces"};
    EXPECT_EQ(wynik, oczekiwany);
}

//zła głębokość
TEST(calculate_stairs, schodyGlebokosc0) {
    StairsResult wynik = calculate_stairs(190, 400);
    StairsResult oczekiwany = {0, 0, 0, false, "Całkowita głębokość schodów przekracza dopuszczalną."};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schodyGlebokosc1) {
    StairsResult wynik = calculate_stairs(200, 300);
    StairsResult oczekiwany = {0, 0, 0, false, "Całkowita głębokość schodów przekracza dopuszczalną."};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schodyGlebokosc2) {
    StairsResult wynik = calculate_stairs(160, 320);
    StairsResult oczekiwany = {0, 0, 0, false, "Całkowita głębokość schodów przekracza dopuszczalną."};
    EXPECT_EQ(wynik, oczekiwany);
}

//zła wysokość
TEST(calculate_stairs, schodyWysokosc0) {
    StairsResult wynik = calculate_stairs(120, 500);
    StairsResult oczekiwany = {0, 0, 0, false, "Nie można dopasować wysokości schodów do wymaganych warunków."};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schodyWysokosc1) {
    StairsResult wynik = calculate_stairs(60, 300);
    StairsResult oczekiwany = {0, 0, 0, false, "Nie można dopasować wysokości schodów do wymaganych warunków."};
    EXPECT_EQ(wynik, oczekiwany);
}
TEST(calculate_stairs, schodyWysokosc2) {
    StairsResult wynik = calculate_stairs(290, 10000);
    StairsResult oczekiwany = {0, 0, 0, false, "Nie można dopasować wysokości schodów do wymaganych warunków."};
    EXPECT_EQ(wynik, oczekiwany);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

