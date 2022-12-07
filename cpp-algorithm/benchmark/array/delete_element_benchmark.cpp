#include "delete_element.h"

#include <benchmark/benchmark.h>

static void BmDeleteDuplicate(benchmark::State& state)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    for (auto _ : state)
    {
        DeleteElement::DeleteDuplicates(numbers);
    }
}
BENCHMARK(BmDeleteDuplicate);

static void BmDeleteDuplicateElements(benchmark::State& state)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    for (auto _ : state)
    {
        DeleteElement::DeleteDuplicateElements(numbers);
    }
}
BENCHMARK(BmDeleteDuplicateElements);

static void BmDeleteSpecificElements(benchmark::State& state)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    constexpr auto element = 11;
    for (auto _ : state)
    {
        DeleteElement::DeleteSpecificElements(numbers, element);
    }
}
BENCHMARK(BmDeleteSpecificElements);

BENCHMARK_MAIN();
