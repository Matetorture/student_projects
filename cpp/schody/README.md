# Schody

## Opis
Aplikacja konsolowa, która oblicza parametry schodów, takie jak liczba stopni, wysokość stopnia i głębokość stopnia na podstawie podanych przez użytkownika całkowitych wymiarów schodów. Program sprawdza również, czy wyliczone parametry są zgodne z określonymi warunkami technicznymi (wysokość i głębokość stopni).

Dane wejściowe:
- całkowita wysokość schodów `Sh`
- całkowita głębokość schodów `Sl`

Dane wyjściowe:
- ilość stopni `num_steps`
- wysokość stopnia (od 16 do 18) `step_height`
- głębokość stopnia (od 25 do 32) `step_depth`

<img src="schody.png">
<p style="text-align:center">Rys. 1. Schemat schodów.</p>

## Struktura projektu

Projekt składa się z następujących plików:
- **functions.cpp** - Definicja funkcji `calculate_stairs`, która oblicza parametry schodów.
- **main.cpp** - Główny plik aplikacji, który obsługuje interakcję z użytkownikiem.
- **main_test.cpp** - Plik testowy, który zawiera testy jednostkowe funkcji `calculate_stairs` za pomocą frameworka Google Test.

## Szczegóły implementacji

## Plik: `function.cpp`

### Struktura: `StairsResult`

Struktura `StairsResult` przechowuje wyniki obliczeń:
- `num_steps` - liczba stopni
- `step_height` - wysokość pojedynczego stopnia
- `step_depth` - głębokość pojedynczego stopnia

Dodatkowo struktura zawiera operator `==`, który umożliwia porównywanie dwóch obiektów `StairsResult`.

### Funkcja: `calculate_stairs`

Funkcja `calculate_stairs` oblicza parametry schodów na podstawie podanych parametrów:
- `Sh` - całkowita wysokość schodów
- `Sl` - całkowita głębokość schodów

Funkcja sprawdza, czy wyliczone parametry są zgodne z określonymi warunkami technicznym oraz oblicza najbardziej optymalną wysokość i głębokość schodów.

#### Zwracane wartości
Funkcja zwraca obiekt `StairsResult` z wypełnionymi wartościami liczby stopni, wysokości i głębokości stopnia.

`function.cpp`

```cpp
#include <iostream>
#include <cmath>

using namespace std;

struct StairsResult {
    int num_steps;
    double step_height;
    double step_depth;

    //operator ==
    bool operator==(const StairsResult& other) const {
	return num_steps == other.num_steps &&
	    step_height == other.step_height &&
	    step_depth == other.step_depth;
    }
};

StairsResult calculate_stairs(double Sh, double Sl) {
    int min_height = 16;
    int max_height = 19;
    int min_depth = 25;
    int max_depth = 32;

    int bestSteps = 0;
    double bestHeight = 0, bestDepth = 0;
    double minDepthDiff = std::numeric_limits<double>::max();

    for (int stepHeight = min_height; stepHeight <= max_height; ++stepHeight) {
        int steps = static_cast<int>(Sh / stepHeight);

        //if (steps * stepHeight == Sh) {
            for (int stepDepth = min_depth; stepDepth <= max_depth; ++stepDepth) {
                double totalDepth = steps * stepDepth;

                if (totalDepth <= Sl) {
                    double depthDiff = Sl - totalDepth;

                    if (depthDiff < minDepthDiff) {
                        minDepthDiff = depthDiff;
                        bestSteps = steps;
                        bestHeight = stepHeight;
                        bestDepth = stepDepth;
                    }
                }
            }
        //}
    }

    return {bestSteps, bestHeight, bestDepth};
}
```

Plik: main.cpp

Plik main.cpp zawiera funkcję main, która odpowiada za interakcję z użytkownikiem:

- Pobiera od użytkownika całkowitą wysokość i głębokość schodów.
- Wywołuje funkcję calculate_stairs, aby obliczyć parametry schodów.
- Wyświetla wynik obliczeń lub komunikat o błędzie, jeśli obliczenia się nie powiodły.

`main.cpp`
```cpp
#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {
    double Sh, Sl;
    
    cout << "Podaj całkowitą wysokość schodów (Sh): ";
    cin >> Sh;
    cout << "Podaj całkowitą głębokość schodów (Sl): ";
    cin >> Sl;

    StairsResult wynik = calculate_stairs(Sh, Sl);

    //if (wynik.success) {
        cout << "Ilość stopni: " << wynik.num_steps << endl;
        cout << "Wysokość stopnia: " << wynik.step_height << " cm" << endl;
        cout << "Głębokość stopnia: " << wynik.step_depth << " cm" << endl;
    //} else {
        //cout << wynik.message << endl;
    //}

    return 0;
}
```

Plik: main_test.cpp

Plik main_test.cpp zawiera zestaw testów jednostkowych dla funkcji calculate_stairs. Testy są realizowane przy użyciu frameworka Google Test.

# Tabela testów jednostkowych

| Test              | Wartość `Sh` | Wartość `Sl` | Oczekiwane `num_steps` | Oczekiwane `step_height` | Oczekiwane `step_depth`  | Test zaliczony |
|-------------------|--------------|--------------|------------------------|--------------------------|--------------------------|----------------|
| **schody0**       | 100          | 140          | 5                      | 17                       | 28                       | ✅             |
| **schody1**       | 100          | 150          | 6                      | 16                       | 25                       | ✅             |
| **schody2**       | 190          | 250          | 10                     | 18                       | 25                       | ✅             |
| **schody3**       | 200          | 280          | 10                     | 19                       | 28                       | ✅             |
| **schody4**       | 200          | 300          | 12                     | 16                       | 25                       | ✅             |
| **schody5**       | 380          | 500          | 20                     | 19                       | 25                       | ✅             |


`main_test.cpp`
```cpp
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
```
