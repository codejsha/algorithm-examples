#include "enumerate_prime_number.h"

#include <benchmark/benchmark.h>

static void BM_GeneratePrimes(benchmark::State& state)
{
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(EnumeratePrime::GeneratePrimes(state.range(0)));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_GeneratePrimes)->Arg(100)->Arg(1000)->Arg(10000)->Complexity(benchmark::oN);

BENCHMARK_MAIN();
