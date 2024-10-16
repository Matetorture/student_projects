# Program sprawdzając funkcje FizzBuzz

Projekt implementuje klasyczne zadanie "FizzBuzz" oraz zawiera odpowiednie testy do sprawdzenia poprawności jego działania. Kod składa się z trzech głównych plików:

- functions.cpp – Zawiera implementację funkcji FizzBuzz.
- main.cpp – Zawiera przykładowe wywołania funkcji FizzBuzz w celu testowania działania kodu.
- main_test.cpp – Zawiera zestaw testów jednostkowych weryfikujących działanie funkcji FizzBuzz.

# Uruchamianie testów

Aby uruchomić testy, należy skompilować plik main_test.cpp. W wyniku zostanie wyświetlony raport z testów, który informuje, czy testy zakończyły się sukcesem.

# Pliki

## Functions

Plik zawiera funkcję FizzBuzz, która dla liczby całkowitej n zwraca:

- "FizzBuzz" – jeżeli liczba n jest podzielna przez 15,
- "Fizz" – jeżeli liczba n jest podzielna przez 3,
- "Buzz" – jeżeli liczba n jest podzielna przez 5,
- pusty string ("") w przeciwnym wypadku.

`functions.cpp`

```cpp
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
```

## Main

Ten plik służy do przetestowania działania funkcji FizzBuzz w sposób manualny poprzez wywołanie jej dla kilku wartości liczbowych i wyświetlenie wyniku.

`main.cpp`

```cpp
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
```

Wynik wyświetlany w konsoli:
```
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
```
## Main test:

Plik zawiera testy jednostkowe funkcji FizzBuzz. Testy sprawdzają różne przypadki:

- Podzielność przez 3 (zwracanie "Fizz"),
- Podzielność przez 5 (zwracanie "Buzz"),
- Podzielność przez 15 (zwracanie "FizzBuzz").

`main_test.cpp`

```cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(FizzBuzzTest, FizzBuzz1) {
   string result = FizzBuzz(1);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz2) {
   string result = FizzBuzz(2);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz3) {
   string result = FizzBuzz(3);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz4) {
   string result = FizzBuzz(4);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz5) {
   string result = FizzBuzz(5);
   EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTest, FizzBuzz6) {
   string result = FizzBuzz(6);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz7) {
   string result = FizzBuzz(7);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz8) {
   string result = FizzBuzz(8);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz9) {
   string result = FizzBuzz(9);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz10) {
   string result = FizzBuzz(10);
   EXPECT_EQ(result, "Buzz");
}

TEST(FizzBuzzTest, FizzBuzz11) {
   string result = FizzBuzz(11);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz12) {
   string result = FizzBuzz(12);
   EXPECT_EQ(result, "Fizz");
}

TEST(FizzBuzzTest, FizzBuzz13) {
   string result = FizzBuzz(13);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz14) {
   string result = FizzBuzz(14);
   EXPECT_EQ(result, "");
}

TEST(FizzBuzzTest, FizzBuzz15) {
   string result = FizzBuzz(15);
   EXPECT_EQ(result, "FizzBuzz");
}

TEST(FizzBuzzTest, FizzBuzz16) {
   string result = FizzBuzz(16);
   EXPECT_EQ(result, "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

# Wyniki testów jednostkowych dla funkcji FizzBuzz

| Test         | Wejście | Oczekiwany wynik | Faktyczny wynik | Status   |
|--------------|---------|------------------|-----------------|----------|
| FizzBuzz1    | 1       | ""               | ""              | ✔️       |
| FizzBuzz2    | 2       | ""               | ""              | ✔️       |
| FizzBuzz3    | 3       | "Fizz"           | "Fizz"          | ✔️       |
| FizzBuzz4    | 4       | ""               | ""              | ✔️       |
| FizzBuzz5    | 5       | "Buzz"           | "Buzz"          | ✔️       |
| FizzBuzz6    | 6       | "Fizz"           | "Fizz"          | ✔️       |
| FizzBuzz7    | 7       | ""               | ""              | ✔️       |
| FizzBuzz8    | 8       | ""               | ""              | ✔️       |
| FizzBuzz9    | 9       | "Fizz"           | "Fizz"          | ✔️       |
| FizzBuzz10   | 10      | "Buzz"           | "Buzz"          | ✔️       |
| FizzBuzz11   | 11      | ""               | ""              | ✔️       |
| FizzBuzz12   | 12      | "Fizz"           | "Fizz"          | ✔️       |
| FizzBuzz13   | 13      | ""               | ""              | ✔️       |
| FizzBuzz14   | 14      | ""               | ""              | ✔️       |
| FizzBuzz15   | 15      | "FizzBuzz"       | "FizzBuzz"      | ✔️       |
| FizzBuzz16   | 16      | ""               | ""              | ✔️       |

## Podsumowanie

Wszystkie testy zakończyły się sukcesem, a wyniki funkcji `FizzBuzz` dla podanych wartości odpowiadają oczekiwanym rezultatom.

