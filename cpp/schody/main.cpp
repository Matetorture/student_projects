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

    if (wynik.num_steps != 0) {
        cout << "Ilość stopni: " << wynik.num_steps << endl;
        cout << "Wysokość stopnia: " << wynik.step_height << " cm" << endl;
        cout << "Głębokość stopnia: " << wynik.step_depth << " cm" << endl;
    } else {
        cout << "Nie da sie stworzyć takich schodów" << endl;
    }

    return 0;
}

