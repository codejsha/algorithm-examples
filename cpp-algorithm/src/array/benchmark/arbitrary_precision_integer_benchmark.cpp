#include "arbitrary_precision_integer.h"

#include <benchmark/benchmark.h>

static void BM_PlusOne(benchmark::State& state)
{
    const auto number = std::vector<int>{1, 2, 9};
    for (auto _ : state)
    {
        ArbitraryPrecision::PlusOne(number);
    }
}

BENCHMARK(BM_PlusOne);

static void BM_StringAddition(benchmark::State& state)
{
    const std::string number1 = "101";
    const std::string number2 = "101";
    for (auto _ : state)
    {
        ArbitraryPrecision::StringAddition(number1, number2);
    }
}

BENCHMARK(BM_StringAddition);

static void BM_Multiply(benchmark::State& state)
{
    auto number1 = std::vector<int>{1, 9, 3, 7, 0, 7, 7, 2, 1};
    auto number2 = std::vector<int>{-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
    for (auto _ : state)
    {
        ArbitraryPrecision::Multiply(number1, number2);
    }
}

BENCHMARK(BM_Multiply);

BENCHMARK_MAIN();
