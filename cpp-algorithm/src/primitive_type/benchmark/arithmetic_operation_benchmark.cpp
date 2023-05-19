#include "arithmetic_operation.h"

#include <benchmark/benchmark.h>

static void BM_Multiply(benchmark::State& state)
{
    for (auto _ : state)
    {
        ArithmeticOperation::Multiply(state.range(0), state.range(1));
    }
}

BENCHMARK(BM_Multiply)->Args({0b1101, 0b1001});

static void BM_Divide(benchmark::State& state)
{
    for (auto _ : state)
    {
        ArithmeticOperation::Divide(state.range(0), state.range(1));
    }
}

BENCHMARK(BM_Divide)->Args({0b1011, 0b10});

BENCHMARK_MAIN();
