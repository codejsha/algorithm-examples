#include "random_data_sampling.h"

#include <benchmark/benchmark.h>

static void BmOfflineRandomSampling(benchmark::State& state)
{
    constexpr auto k = 3;
    auto arr = std::vector<int>{3, 7, 5, 11};
    for (auto _ : state)
    {
        RandomDataSampling::OfflineRandomSampling(k, arr);
    }
}
BENCHMARK(BmOfflineRandomSampling);

static void BmComputeRandomPermutation(benchmark::State& state)
{
    constexpr auto k = 3;
    auto arr = std::vector<int>{3, 7, 5, 11};
    for (auto _ : state)
    {
        RandomDataSampling::ComputeRandomPermutation(k);
    }
}
BENCHMARK(BmComputeRandomPermutation);

BENCHMARK_MAIN();
