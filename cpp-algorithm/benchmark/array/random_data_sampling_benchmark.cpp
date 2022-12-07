#include "random_data_sampling.h"

#include <benchmark/benchmark.h>

static void BM_OfflineRandomSampling(benchmark::State& state)
{
    constexpr auto k = 3;
    auto arr = std::vector<int>{3, 7, 5, 11};
    for (auto _ : state)
    {
        RandomDataSampling::OfflineRandomSampling(k, arr);
    }
}
BENCHMARK(BM_OfflineRandomSampling);

static void BM_ComputeRandomPermutation(benchmark::State& state)
{
    constexpr auto k = 3;
    for (auto _ : state)
    {
        RandomDataSampling::ComputeRandomPermutation(k);
    }
}
BENCHMARK(BM_ComputeRandomPermutation);

BENCHMARK_MAIN();
