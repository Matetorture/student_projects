# Benchmark Sortowanie

## Opis ogólny
Poniższy zestaw testów ma na celu porównanie wydajności dwóch różnych algorytmów sortowania: **Quick Sort** oraz **Bubble Sort**. Testy mierzą czas potrzebny na posortowanie wektora składającego się z 10,000 losowych liczb całkowitych. Czas jest mierzony przy pomocy standardowej biblioteki `chrono`, a wyniki są wyświetlane w sekundach.

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

## Autorzy

- [Przemysław P](https://github.com/Matetorture)
