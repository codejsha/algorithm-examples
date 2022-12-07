#include "rabin_karp.h"

#include <benchmark/benchmark.h>

static void BM_RabinKarpMatcher1(benchmark::State& state)
{
    for (auto _ : state)
    {
        RabinKarp::RabinKarpMatcher1("abcabaabcabac", "abaa");
    }
}
BENCHMARK(BM_RabinKarpMatcher1);

static void BM_RabinKarpMatcher2(benchmark::State& state)
{
    for (auto _ : state)
    {
        RabinKarp::RabinKarpMatcher2("abcabaabcabac", "abaa");
    }
}
BENCHMARK(BM_RabinKarpMatcher2);

BENCHMARK_MAIN();
