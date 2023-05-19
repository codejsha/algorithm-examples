#include "naive_string_match.h"

#include <benchmark/benchmark.h>

static void BM_NaiveStringMatcher(benchmark::State& state)
{
    for (auto _ : state)
    {
        NaiveStringMatch::NaiveStringMatcher("eceyeye", "eye");
    }
}

BENCHMARK(BM_NaiveStringMatcher);

BENCHMARK_MAIN();
