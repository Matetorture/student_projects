#include <iostream>
#include "functions.cpp"

using namespace std;

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

