#include "interval_subset_sum_problem.h"

#include <benchmark/benchmark.h>

static void BM_SubsetSum1(benchmark::State& state)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    for (auto _ : state)
    {
        IntervalSubset::SubsetSum1(seq);
    }
}

BENCHMARK(BM_SubsetSum1);

static void BM_SubsetSum2(benchmark::State& state)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    for (auto _ : state)
    {
        IntervalSubset::SubsetSum2(seq);
    }
}

BENCHMARK(BM_SubsetSum2);

static void BM_DivideAndConquerSubsetSum(benchmark::State& state)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    for (auto _ : state)
    {
        constexpr auto low = 0;
        const auto high = static_cast<int>(seq.size() - 1);
        IntervalSubset::DivideAndConquerSubsetSum(seq, low, high);
    }
}

BENCHMARK(BM_DivideAndConquerSubsetSum);

static void BM_DynamicProgrammingSubsetSum(benchmark::State& state)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    for (auto _ : state)
    {
        IntervalSubset::DynamicProgrammingSubsetSum(seq);
    }
}

BENCHMARK(BM_DynamicProgrammingSubsetSum);

BENCHMARK_MAIN();
