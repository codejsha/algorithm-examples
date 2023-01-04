#include "advancing_through.h"

#include <benchmark/benchmark.h>

static void BM_CanReachEnd(benchmark::State& state)
{
    const auto v = std::vector<int>{3, 3, 1, 0, 2, 0, 1};
    for (auto _ : state)
    {
        AdvancingThrough::CanReachEnd(v);
    }
}
BENCHMARK(BM_CanReachEnd);

BENCHMARK_MAIN();
