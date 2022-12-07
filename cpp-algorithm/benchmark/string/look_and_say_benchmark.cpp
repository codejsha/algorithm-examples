#include "look_and_say.h"

#include <benchmark/benchmark.h>

static void BM_LookAndSayProblem(benchmark::State& state)
{
    for (auto _ : state)
    {
        LookAndSay::LookAndSayProblem("13112221");
    }
}
BENCHMARK(BM_LookAndSayProblem);

BENCHMARK_MAIN();
