Dokumentacja do projektu FizzBuzz

Ten projekt implementuje klasyczne zadanie "FizzBuzz" oraz zawiera odpowiednie testy do sprawdzenia poprawności jego działania. Kod składa się z trzech głównych plików:

    functions.cpp – Zawiera implementację funkcji FizzBuzz.
    main.cpp – Zawiera przykładowe wywołania funkcji FizzBuzz w celu testowania działania kodu.
    main_test.cpp – Zawiera zestaw testów jednostkowych wykorzystujących bibliotekę Google Test do weryfikacji działania funkcji FizzBuzz.

Pliki
functions.cpp

Plik zawiera funkcję FizzBuzz, która dla liczby całkowitej n zwraca:

    "FizzBuzz" – jeżeli liczba n jest podzielna przez 15,
    "Fizz" – jeżeli liczba n jest podzielna przez 3,
    "Buzz" – jeżeli liczba n jest podzielna przez 5,
    pusty string ("") w przeciwnym wypadku.

Kod

cpp

#include <string>

using namespace std;

string FizzBuzz(int n){
  if(n % 15 == 0){
    return "FizzBuzz";
  } else if(n % 3 == 0){
    return "Fizz";
  } else if(n % 5 == 0){
    return "Buzz";
  }
  return "";
}

main.cpp

Ten plik służy do przetestowania działania funkcji FizzBuzz w sposób manualny poprzez wywołanie jej dla kilku wartości liczbowych i wyświetlenie wyniku.
Kod

cpp

#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {
    cout << "-=-=-=-=-=-=-=-=-" << endl;
    for(int i = 1; i <= 15; i++) {
        cout << i << " " << FizzBuzz(i) << endl;
    }
    cout << "-=-=-=-=-=-=-=-=-" << endl;
    return 0;
}

Przykładowe wyjście programu:

1 
2 
3 Fizz
4 
5 Buzz
6 Fizz
7 
8 
9 Fizz
10 Buzz
11 
12 Fizz
13 
14 
15 FizzBuzz

main_test.cpp

Plik zawiera testy jednostkowe funkcji FizzBuzz, które zostały napisane przy użyciu biblioteki Google Test. Testy sprawdzają różne przypadki, w tym:

    Podzielność przez 3 (zwracanie "Fizz"),
    Podzielność przez 5 (zwracanie "Buzz"),
    Podzielność przez 15 (zwracanie "FizzBuzz").

Kod

cpp

// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(FizzBuzzTest, Fizz) {
   string result = FizzBuzz(3);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, Buzz) {
   string result = FizzBuzz(5);
   EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTest, FizzBuzz) {
   string result = FizzBuzz(15);
   EXPECT_EQ(result, "FizzBuzz");
}

// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

Uruchamianie testów

Aby uruchomić testy, należy skompilować plik main_test.cpp z biblioteką Google Test i uruchomić powstały program. W wyniku zostanie wyświetlony raport z testów, który informuje, czy testy zakończyły się sukcesem.