#include "advancing_through.h"

#include <benchmark/benchmark.h>

static void BmPlusOne(benchmark::State& state)
{
    const auto v = std::vector<int>{3, 3, 1, 0, 2, 0, 1};
    for (auto _ : state)
    {
        AdvancingThrough::CanReachEnd(v);
    }
}
BENCHMARK(BmPlusOne);

BENCHMARK_MAIN();
