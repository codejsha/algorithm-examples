#include "merge_sorted_array.h"

#include <benchmark/benchmark.h>

static void BM_MergeSortedArray(benchmark::State& state)
{
    const auto arr1 = std::vector{1, 3, 5, 7, 9};
    const auto arr2 = std::vector{2, 4, 6, 8, 10};
    const auto arr3 = std::vector{5, 10};

    for (auto _ : state)
    {
        MergeSortedArray::MergeSortedArray(arr1, arr2, arr3);
    }
}

BENCHMARK(BM_MergeSortedArray);

BENCHMARK_MAIN();
