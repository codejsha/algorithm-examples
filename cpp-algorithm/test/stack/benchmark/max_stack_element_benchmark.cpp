#include "max_stack_element.h"

#include <benchmark/benchmark.h>

static void BM_Empty(benchmark::State& state)
{
    const auto stack = MaxStackElement::Stack{};
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stack.Empty());
    }
}
BENCHMARK(BM_Empty);

static void BM_Push(benchmark::State& state)
{
    auto stack = MaxStackElement::Stack{};
    for (auto _ : state)
    {
        stack.Push(state.range(0));
    }
}
BENCHMARK(BM_Push)->DenseRange(1, 3, 1);

static void BM_Max(benchmark::State& state)
{
    auto stack = MaxStackElement::Stack{};
    stack.Push(3);
    stack.Push(2);
    stack.Push(4);
    stack.Push(1);
    stack.Push(5);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(stack.Max());
    }
}
BENCHMARK(BM_Max);

BENCHMARK_MAIN();
