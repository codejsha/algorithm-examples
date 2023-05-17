#include "fibonacci_number.h"

#include <benchmark/benchmark.h>

static void BM_FibonacciDynamicTopDown(benchmark::State& state)
{
    constexpr auto number = 8;
    auto memo = std::vector<int>(number + 1, -1);
    for (auto _ : state)
    {
        Fibonacci::FibonacciDynamicTopDown(number, memo);
    }
}
BENCHMARK(BM_FibonacciDynamicTopDown);

static void BM_FibonacciDynamicBottomUp(benchmark::State& state)
{
    constexpr auto number = 8;
    for (auto _ : state)
    {
        Fibonacci::FibonacciDynamicBottomUp(number);
    }
}
BENCHMARK(BM_FibonacciDynamicBottomUp);

BENCHMARK_MAIN();
