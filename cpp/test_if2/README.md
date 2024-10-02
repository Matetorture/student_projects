# Benchmark `if`, `if else`, `if else if`, `switch default`, `switch` statements in C++

## Cel
Celem tego benchmarku jest porównanie czasu wykonywania różnych struktur warunkowych w języku C++: `if`, `if else`, `if else if`, `switch default` oraz `switch`. Testowane są różne implementacje struktur warunkowych, aby określić, która z nich działa najszybciej w specyficznych warunkach.

## Opis testów
Każdy test mierzy czas potrzebny do wykonania jednej z poniższych struktur warunkowych:
1. **if** - proste sprawdzenie warunku.
2. **if else** - sprawdzenie warunku z blokiem alternatywnym.
3. **if else if** - sprawdzenie kilku warunków.
4. **switch z default** - switch z domyślnym przypadkiem.
5. **switch bez default** - switch bez domyślnego przypadku.

Wszystkie testy są uruchamiane przy użyciu GoogleTest i mierzą czas wykonywania przy pomocy (`std::chrono::high_resolution_clock`).

## Wyniki

| Struktura            | Czas (s) |
|----------------------|----------|
| `if`                 | 0.000001 |
| `if else`            | 0.000002 |
| `if else if`         | 0.000002 |
| `switch z default`   | 0.000001 |
| `switch bez default` | 0.000001 |

## Kod źródłowy

```cpp
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
    auto start = std::chrono::high_resolution_clock::now();
    bool result = test_if(0);
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
    } else {
        test = true;
    }
    return test;
}

TEST(BenchmarkTest, IfElseBenchmark) {
    auto start = std::chrono::high_resolution_clock::now();
    bool result = test_if_else(0);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas if else: " << elapsed_seconds.count() << "s\n";
}

/////////////////////////////////////////////////////
// benchmark if else if
static bool test_if_else_if(int i){
    bool test = false;
    if(i == 1){
        test = false;
    } else if(i == 2){
        test = true;
    } else {
        test = false;
    }
    return test;
}

TEST(BenchmarkTest, IfElseIfBenchmark) {
    auto start = std::chrono::high_resolution_clock::now();
    bool result = test_if_else_if(2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas if else if: " << elapsed_seconds.count() << "s\n";
}

/////////////////////////////////////////////////////
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
    auto start = std::chrono::high_resolution_clock::now();
    bool result = test_switch_default(3);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas switch (z default): " << elapsed_seconds.count() << "s\n";
}

/////////////////////////////////////////////////////
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
    auto start = std::chrono::high_resolution_clock::now();
    bool result = test_switch(0);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas switch: " << elapsed_seconds.count() << "s\n";
}

/////////////////////////////////////////////////////
// uruchomienie benchmarków
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## Autorzy

- [Przemysław P](https://github.com/Matetorture)
