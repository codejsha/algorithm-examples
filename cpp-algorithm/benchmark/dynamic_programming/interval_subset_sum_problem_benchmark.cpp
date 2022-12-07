#include "interval_subset_sum_problem.h"

#include <benchmark/benchmark.h>

static void BM_SimpleSubsetSum1(benchmark::State& state)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    for (auto _ : state)
    {
        IntervalSubset::SimpleSubsetSum1(seq);
    }
}
BENCHMARK(BM_SimpleSubsetSum1);

static void BM_SimpleSubsetSum2(benchmark::State& state)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    for (auto _ : state)
    {
        IntervalSubset::SimpleSubsetSum2(seq);
    }
}
BENCHMARK(BM_SimpleSubsetSum2);

static void BM_DivideAndConquerSubsetSum(benchmark::State& state)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    for (auto _ : state)
    {
        IntervalSubset::DivideAndConquerSubsetSum(seq, 0, static_cast<int>(seq.size() - 1));
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
