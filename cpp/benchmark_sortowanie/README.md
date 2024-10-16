# Benchmark Sortowanie

## Opis ogólny
Zestaw testów ma na celu porównanie wydajności dwóch różnych algorytmów sortowania: **Quick Sort** oraz **Bubble Sort**. Testy mierzą czas potrzebny na posortowanie wektora składającego się z 10,000 losowych liczb całkowitych. Czas jest mierzony przy pomocy standardowej biblioteki `chrono`, a wyniki są wyświetlane w sekundach.

## Struktura testów

Testy składają się z dwóch głównych bloków:
1. **Quick Sort Benchmark** - Test sortowania przy pomocy algorytmu Quick Sort.
2. **Bubble Sort Benchmark** - Test sortowania przy pomocy algorytmu Bubble Sort.

Oba testy działają na tym samym wektorze danych, aby zapewnić równe warunki porównawcze.

---

## Test: `BenchmarkTest, QuickSortBenchmark`

### Cel:
Celem tego testu jest zmierzenie czasu wykonania algorytmu Quick Sort na wektorze o wielkości 10,000 elementów.

### Kroki:
1. Inicjalizacja wektora `vec` o rozmiarze 10,000.
2. Wypełnienie wektora losowymi wartościami przy użyciu funkcji `std::generate` oraz generatora `std::rand()`.
3. Rozpoczęcie pomiaru czasu przy pomocy `std::chrono::high_resolution_clock::now()`.
4. Wywołanie funkcji `quickSort` na wektorze.
5. Zakończenie pomiaru czasu oraz obliczenie upływu czasu.
6. Wyświetlenie wyniku w sekundach.

## Kod źródłowy

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>
#include "../cwiczenie1/main.cpp" //bubble sort
#include "../cwiczenie2/main.cpp" //quick sort

// Test wydajności sortowania QuickSort
TEST(BenchmarkTest, QuickSortBenchmark) {
    std::vector<int> vec(10000); // Tworzymy wektor z 10000 losowymi liczbami
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(vec.begin(), vec.end(), std::rand);

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

	//bubbleSort(vec);
	quickSort(vec, 0, vec.size() - 1);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}

TEST(BenchmarkTest, BubbleSortBenchmark) {
    std::vector<int> vec(10000); // Tworzymy wektor z 10000 losowymi liczbami
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(vec.begin(), vec.end(), std::rand);

    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

	bubbleSort(vec);
	//quickSort(vec, 0, vec.size() - 1);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas sortowania: " << elapsed_seconds.count() << "s\n";
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
## Wyniki

| Algorytm     | Rozmiar Danych | Czas Sortowania (s) |
|--------------|----------------|---------------------|
| Bubble Sort  | 10,000         | 0                   |
| Quick Sort   | 10,000         | 0                   |

## Autorzy

- [Przemysław P](https://github.com/Matetorture)
