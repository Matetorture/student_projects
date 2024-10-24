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
