#include "delete_element.h"

#include <benchmark/benchmark.h>

static void BM_DeleteDuplicates(benchmark::State& state)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    for (auto _ : state)
    {
        DeleteElement::DeleteDuplicates(numbers);
    }
}
BENCHMARK(BM_DeleteDuplicates);

static void BM_DeleteDuplicateElements(benchmark::State& state)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    for (auto _ : state)
    {
        DeleteElement::DeleteDuplicateElements(numbers);
    }
}
BENCHMARK(BM_DeleteDuplicateElements);

static void BM_DeleteSpecificElements(benchmark::State& state)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    constexpr auto element = 11;
    for (auto _ : state)
    {
        DeleteElement::DeleteSpecificElements(numbers, element);
    }
}
BENCHMARK(BM_DeleteSpecificElements);

BENCHMARK_MAIN();
