# Schody

Wynik:
- ilość stopni 
- wysokość stpnia (od 15 do 19)
- głębokość stopnia (od 50 do 70)

Podajemy:
- całkowita wysokość schodów (Sh)
- całkowita głębokość schodów (sl)



#include <iostream>
#include <cmath>

using namespace std;

struct StairsResult {
    int num_steps;
    double step_height;
    double step_depth;
    bool success;
    string message;
};

StairsResult calculate_stairs(double Sh, double Sl) {
    // Ustalamy granice wysokości i głębokości stopnia
    const double min_height = 15.0;  // Minimalna wysokość stopnia
    const double max_height = 19.0;  // Maksymalna wysokość stopnia
    const double min_depth = 50.0;   // Minimalna głębokość stopnia
    const double max_depth = 70.0;   // Maksymalna głębokość stopnia

    // Wyznaczamy minimalną liczbę stopni dla maksymalnej dopuszczalnej wysokości
    int num_steps = static_cast<int>(Sh / max_height);

    // Jeśli schody się nie rozkładają równo, zwiększamy liczbę stopni
    if (fmod(Sh, max_height) != 0) {
        num_steps += 1;
    }

    // Obliczamy wysokość jednego stopnia
    double step_height = Sh / num_steps;

    // Sprawdzamy, czy wysokość mieści się w wymaganym przedziale
    if (step_height < min_height || step_height > max_height) {
        return {0, 0, 0, false, "Nie można dopasować wysokości schodów do wymaganych warunków."};
    }

    // Obliczamy minimalną głębokość wszystkich stopni
    double total_depth = min_depth * num_steps;

    // Sprawdzamy, czy całkowita głębokość mieści się w dopuszczalnym zakresie
    if (total_depth > Sl) {
        return {0, 0, 0, false, "Całkowita głębokość schodów przekracza dopuszczalną."};
    }

    // Zmniejszamy liczbę stopni, aby zbliżyć się do maksymalnej głębokości bez przekroczenia
    double step_depth = Sl / num_steps;

    // Sprawdzamy, czy głębokość jednego stopnia mieści się w dopuszczalnym przedziale
    if (step_depth < min_depth || step_depth > max_depth) {
        return {0, 0, 0, false, "Nie można dopasować głębokości schodów do wymaganych warunków."};
    }

    return {num_steps, step_height, step_depth, true, "Sukces"};
}

int main() {
    double Sh, Sl;
    
    // Pobieranie wartości od użytkownika
    cout << "Podaj całkowitą wysokość schodów (Sh): ";
    cin >> Sh;
    cout << "Podaj całkowitą głębokość schodów (Sl): ";
    cin >> Sl;

    // Wywołanie funkcji obliczającej schody
    StairsResult wynik = calculate_stairs(Sh, Sl);

    // Sprawdzamy, czy operacja się powiodła
    if (wynik.success) {
        cout << "Ilość stopni: " << wynik.num_steps << endl;
        cout << "Wysokość stopnia: " << wynik.step_height << " cm" << endl;
        cout << "Głębokość stopnia: " << wynik.step_depth << " cm" << endl;
    } else {
        // Wyświetlamy wiadomość o błędzie
        cout << wynik.message << endl;
    }

    return 0;
}


# Dokumentacja do projektu: Schody

Ten projekt to aplikacja konsolowa, która oblicza parametry schodów, takie jak liczba stopni, wysokość stopnia i głębokość stopnia na podstawie podanych przez użytkownika całkowitych wymiarów schodów. Program sprawdza również, czy wyliczone parametry są zgodne z określonymi warunkami technicznymi (wysokość i głębokość stopni).

## Struktura projektu

Projekt składa się z trzech głównych plików:
- `function.cpp` - zawiera funkcję `calculate_stairs`, która oblicza parametry schodów.
- `main.cpp` - funkcja główna programu, która pobiera dane wejściowe od użytkownika i wyświetla wynik obliczeń.
- `main_test.cpp` - zestaw testów jednostkowych sprawdzających poprawność działania funkcji `calculate_stairs`.

## Plik: function.cpp

### Struktura: `StairsResult`

Struktura `StairsResult` przechowuje wyniki obliczeń:
- `num_steps` - liczba stopni
- `step_height` - wysokość pojedynczego stopnia
- `step_depth` - głębokość pojedynczego stopnia
- `success` - wartość logiczna wskazująca, czy obliczenia zakończyły się sukcesem
- `message` - wiadomość informacyjna o wyniku obliczeń

Dodatkowo struktura zawiera przeciążony operator `==`, który umożliwia porównywanie dwóch obiektów `StairsResult`.

### Funkcja: `calculate_stairs`

Funkcja `calculate_stairs` oblicza parametry schodów na podstawie podanych parametrów:
- `Sh` - całkowita wysokość schodów
- `Sl` - całkowita głębokość schodów

Funkcja sprawdza, czy wyliczone parametry są zgodne z określonymi warunkami technicznymi:
- Wysokość stopnia musi mieścić się w zakresie od 15 cm do 19 cm.
- Głębokość stopnia musi mieścić się w zakresie od 50 cm do 70 cm.

#### Zwracane wartości
Funkcja zwraca obiekt `StairsResult` z wypełnionymi wartościami liczby stopni, wysokości i głębokości stopnia. Jeśli obliczenia nie spełniają wymagań, funkcja zwraca `success` ustawione na `false` i odpowiednią wiadomość w `message`.

#### Kod funkcji `calculate_stairs`
```cpp
StairsResult calculate_stairs(double Sh, double Sl) {
    double min_height = 15.0;
    double max_height = 19.0;
    double min_depth = 50.0;
    double max_depth = 70.0;

    int num_steps = static_cast<int>(Sh / max_height);

    if (fmod(Sh, max_height) != 0) {
        num_steps += 1;
    }

    double step_height = Sh / num_steps;

    if (step_height < min_height || step_height > max_height) {
        return {0, 0, 0, false, "Nie można dopasować wysokości schodów do wymaganych warunków."};
    }

    double total_depth = min_depth * num_steps;

    if (total_depth > Sl) {
        return {0, 0, 0, false, "Całkowita głębokość schodów przekracza dopuszczalną."};
    }

    double step_depth = Sl / num_steps;

    if (step_depth < min_depth || step_depth > max_depth) {
        return {0, 0, 0, false, "Nie można dopasować głębokości schodów do wymaganych warunków."};
    }

    return {num_steps, step_height, step_depth, true, "Sukces"};
}

Plik: main.cpp

Plik main.cpp zawiera funkcję main, która odpowiada za interakcję z użytkownikiem:

    Pobiera od użytkownika całkowitą wysokość i głębokość schodów.
    Wywołuje funkcję calculate_stairs, aby obliczyć parametry schodów.
    Wyświetla wynik obliczeń lub komunikat o błędzie, jeśli obliczenia się nie powiodły.

Kod funkcji main

cpp

int main() {
    double Sh, Sl;

    cout << "Podaj całkowitą wysokość schodów (Sh): ";
    cin >> Sh;
    cout << "Podaj całkowitą głębokość schodów (Sl): ";
    cin >> Sl;

    StairsResult wynik = calculate_stairs(Sh, Sl);

    if (wynik.success) {
        cout << "Ilość stopni: " << wynik.num_steps << endl;
        cout << "Wysokość stopnia: " << wynik.step_height << " cm" << endl;
        cout << "Głębokość stopnia: " << wynik.step_depth << " cm" << endl;
    } else {
        cout << wynik.message << endl;
    }

    return 0;
}

Plik: main_test.cpp

Plik main_test.cpp zawiera zestaw testów jednostkowych dla funkcji calculate_stairs. Testy są realizowane przy użyciu frameworka Google Test.
Kategorie testów

Testy zostały podzielone na trzy główne grupy:

    Schody możliwe: Testy sprawdzające, czy obliczenia są poprawne dla prawidłowych wartości wejściowych.
    Zła głębokość: Testy sprawdzające, czy funkcja poprawnie obsługuje przypadki, gdy całkowita głębokość schodów przekracza dopuszczalną wartość.
    Zła wysokość: Testy sprawdzające, czy funkcja poprawnie obsługuje przypadki, gdy wysokość stopnia nie mieści się w zakresie dopuszczalnych wartości.

Przykładowe testy

cpp

// Test dla poprawnych wartości wejściowych
TEST(calculate_stairs, schodyMozliwe0) {
    StairsResult wynik = calculate_stairs(180, 500);
    StairsResult oczekiwany = {10, 18, 50, true, "Sukces"};
    EXPECT_EQ(wynik, oczekiwany);
}

// Test dla zbyt dużej głębokości
TEST(calculate_stairs, schodyGlebokosc0) {
    StairsResult wynik = calculate_stairs(190, 400);
    StairsResult oczekiwany = {0, 0, 0, false, "Całkowita głębokość schodów przekracza dopuszczalną."};
    EXPECT_EQ(wynik, oczekiwany);
}

// Test dla zbyt małej wysokości
TEST(calculate_stairs, schodyWysokosc0) {
    StairsResult wynik = calculate_stairs(120, 500);
    StairsResult oczekiwany = {0, 0, 0, false, "Nie można dopasować wysokości schodów do wymaganych warunków."};
    EXPECT_EQ(wynik, oczekiwany);
}

Uruchomienie testów

Aby uruchomić testy:

    Skonfiguruj projekt do używania frameworka Google Test.
    Skopiuj kod do odpowiednich plików.
    Uruchom komendę ./main_test (lub równoważną dla używanej platformy).

Uwagi końcowe

Kod został zaprojektowany tak, aby obsługiwać przypadki błędne, gdy obliczone wartości nie spełniają założeń technicznych. Wyniki są prezentowane w sposób przejrzysty dla użytkownika. Testy jednostkowe pozwalają na walidację poprawności implementacji i wykrywają potencjalne błędy w kodzie.


