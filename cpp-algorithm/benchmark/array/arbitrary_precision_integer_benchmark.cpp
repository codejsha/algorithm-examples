#include "arbitrary_precision_integer.h"

#include <benchmark/benchmark.h>

static void BmPlusOne(benchmark::State& state)
{
    const auto number = std::vector<int>{1, 2, 9};
    for (auto _ : state)
    {
        ArbitraryPrecision::PlusOne(number);
    }
}
BENCHMARK(BmPlusOne);

static void BmStringAddition(benchmark::State& state)
{
    const auto number1 = std::string{"101"};
    const auto number2 = std::string{"101"};
    for (auto _ : state)
    {
        ArbitraryPrecision::StringAddition(number1, number2);
    }
}
BENCHMARK(BmStringAddition);

static void BmMultiply(benchmark::State& state)
{
    auto number1 = std::vector<int>{1, 9, 3, 7, 0, 7, 7, 2, 1};
    auto number2 = std::vector<int>{-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
    for (auto _ : state)
    {
        ArbitraryPrecision::Multiply(number1, number2);
    }
}
BENCHMARK(BmMultiply);

BENCHMARK_MAIN();
