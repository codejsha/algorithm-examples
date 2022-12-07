#include "enumerate_prime_number.h"

#include <benchmark/benchmark.h>

static void BM_GeneratePrimes(benchmark::State& state)
{
    for (auto _ : state)
    {
        EnumeratePrime::GeneratePrimes(100);
    }
}
BENCHMARK(BM_GeneratePrimes);

BENCHMARK_MAIN();
