#include "enumerate_prime_number.h"

#include <benchmark/benchmark.h>

static void BmGeneratePrimes(benchmark::State& state)
{
    for (auto _ : state)
    {
        EnumeratePrime::GeneratePrimes(100);
    }
}
BENCHMARK(BmGeneratePrimes);

BENCHMARK_MAIN();
