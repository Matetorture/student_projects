#include <iostream>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

/////////////////////////////////////////////////////

// benchmark if
static bool test_if(int i){
    bool test = false;
    if(i == 1){
        test = false;
    }
    return test;
}

TEST(BenchmarkTest, IfBenchmark) {
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bool result = test_if(0);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas if: " << elapsed_seconds.count() << "s\n";
}

/////////////////////////////////////////////////////

// benchmark if else
static bool test_if_else(int i){
    bool test = false;
    if(i == 1){
        test = false;
    }else{
        test = true;
    }
    return test;
}

TEST(BenchmarkTest, IfElseBenchmark) {
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bool result = test_if_else(0);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas if else: " << elapsed_seconds.count() << "s\n";
}

/////////////////////////////////////////////////////

// test if else if
static bool test_if_else_if(int i){
    bool test = false;
    if(i == 1){
        test = false;
    }else if(i == 2){
        test = true;
    }else{
        test = false;
    }
    return test;
}

TEST(BenchmarkTest, IfElseIfBenchmark) {
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bool result = test_if_else_if(2);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas if else if: " << elapsed_seconds.count() << "s\n";
}

///////////////////////////////////////////////////////

// benchmark switch with default case
static bool test_switch_default(int i){
    bool test = false;
    switch(i){
    case 1:
        test = false;
        break;
    case 2:
        test = true;
        break;
    default:
        test = false;
        break;
    }
    return test;
}

TEST(BenchmarkTest, SwitchDefaultBenchmark) {
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bool result = test_switch_default(3); // testuje przypadek 'default'

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas switch (z default): " << elapsed_seconds.count() << "s\n";
}

///////////////////////////////////////////////////////

// benchmark switch (bez default)
static bool test_switch(int i){
    bool test = false;
    switch(i){
    case 1:
        test = false;
        break;
    case 0:
        test = true;
        break;
    }
    return test;
}

TEST(BenchmarkTest, SwitchBenchmark) {
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    bool result = test_switch(0);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas switch: " << elapsed_seconds.count() << "s\n";
}


/////////////////////////////////////////////////////
//uruchomienie benchmarków

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
