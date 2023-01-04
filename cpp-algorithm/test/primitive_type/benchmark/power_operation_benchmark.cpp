#include "power_operation.h"

#include <benchmark/benchmark.h>

static void BM_Power(benchmark::State& state)
{
    for (auto _ : state)
    {
        PowerOperation::Power(state.range(0), state.range(1));
    }
}
BENCHMARK(BM_Power)->Args({0b10, 0b10});

BENCHMARK_MAIN();
