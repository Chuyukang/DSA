#include <benchmark/benchmark.h>
#include <vector>
#include "algo/sort.h"
#include "algo/quicksort.h"
#include "algo/heapsort.h"

std::vector<int> testcase;

std::vector<int> ConstructRandomVector(size_t size) {
    std::vector<int> vec;
    for(int i=0;i<size;i++) {
        vec.push_back(rand());
    }
    return vec;
}

static void DoSetup(const benchmark::State& state) {
    testcase = ConstructRandomVector(state.range(0));
}

static void BM_QuickSort(benchmark::State& state) {
    std::vector<int> vec;
    sortAlgo* sorter = new quicksortAlgo();
    for (auto _ : state) {
        state.PauseTiming();
        vec = testcase; // copy testcase out
        state.ResumeTiming();

        sorter->sort(vec);
    }
}

BENCHMARK(BM_QuickSort)
    ->Args({100})
    ->Args({1000})
    ->Args({10000})
    ->Setup(DoSetup);


static void BM_HeapSort(benchmark::State& state) {
    std::vector<int> vec;
    sortAlgo* sorter = new heapsortAlgo();
    for (auto _ : state) {
        state.PauseTiming();
        vec = testcase; // copy testcase out
        state.ResumeTiming();

        sorter->sort(vec);
    }
}

// note: two benchmarks do not use same input, but generate independently
BENCHMARK(BM_HeapSort)
        ->Args({100})
        ->Args({1000})
        ->Args({10000})
        ->Setup(DoSetup);

BENCHMARK_MAIN();
