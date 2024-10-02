#include "benchmark/benchmark.h"

int i =  0;

/////////////////////////////////////////////////////

// benchmark

static bool test_if(){
	bool test = false;
	if(i == 1){
		test = false;
	}else{
		test = true;
	}
	return test;
}

static void BM_if(benchmark::State& state) {
    for (auto _ : state) {
        // Benchmarkowany kod
        bool result = test_if();
	benchmark::DoNotOptimize(result);
    }
}

///////////////////////////////////////////////////////

// benchmark

static bool test_swich(){
	bool test = false;
	if(i == 1){
		test = false;
	}else{
		test = true;
	}
	return test;
}

static void BM_swich(benchmark::State& state) {
    for (auto _ : state) {
        // Benchmarkowany kod
        bool result = test_swich();
        benchmark::DoNotOptimize(result);
    }
}

/////////////////////////////////////////////////////
//uruchomienie benchmarków

BENCHMARK(BM_if);
BENCHMARK(BM_swich);

BENCHMARK_MAIN();

