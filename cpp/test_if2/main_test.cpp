#include <iostream>
#include <algorithm>
#include <ctime>
#include "gtest/gtest.h"
#include <chrono>

/////////////////////////////////////////////////////

// benchmark
static bool test_if(int i){
	bool test = false;
	if(i == 1){
		test = false;
	}else{
		test = true;
	}
	return test;
}

TEST(BenchmarkTest, IfBenchmark) {
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

	//bubbleSort(vec);
	bool result = test_if(0);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas if: " << elapsed_seconds.count() << "s\n";
}


///////////////////////////////////////////////////////

// benchmark
static bool test_swich(int i){
	bool test = false;
	swich(i){
	case 1:
		test = false;
		break;
	case 0:
		test = true;
		break;
	return test;
}

TEST(BenchmarkTest, SwichBenchmark) {
    
    // Początek pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

	//bubbleSort(vec);
	bool result = test_swich(0);

    // Koniec pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Czas swich: " << elapsed_seconds.count() << "s\n";
}


/////////////////////////////////////////////////////
//uruchomienie benchmarków

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
