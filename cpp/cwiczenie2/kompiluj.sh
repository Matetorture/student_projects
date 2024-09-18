#!/bin/sh

echo "----Kompilacja programu----"
g++ -o main main.cpp | more
echo "---Kompilacja ukonczona----"
echo "---Uruchamianie programu---"
chmod +x main
./main
echo "---Zakonczono program---"
