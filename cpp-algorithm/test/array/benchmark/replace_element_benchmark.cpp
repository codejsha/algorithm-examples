#include "replace_element.h"

#include <benchmark/benchmark.h>

static void BM_ReplaceAndRemoveString1(benchmark::State& state)
{
    auto arr = std::vector<std::string>{"a", "c", "d", "b", "b", "c", "a"};
    for (auto _ : state)
    {
        ReplaceElement::ReplaceAndRemoveString1(arr, "a", "b");
    }
}
BENCHMARK(BM_ReplaceAndRemoveString1);

static void BM_ReplaceAndRemoveString2(benchmark::State& state)
{
    auto arr = std::vector<std::string>{"a", "c", "d", "b", "b", "c", "a"};
    for (auto _ : state)
    {
        ReplaceElement::ReplaceAndRemoveString2(arr, "a", "b");
    }
}
BENCHMARK(BM_ReplaceAndRemoveString2);

static void BM_TelexEncoding(benchmark::State& state)
{
    //auto v = std::vector<std::string>{"."};
    //auto v = std::vector<std::string>{","};
    //auto v = std::vector<std::string>{"?"};
    auto v = std::vector<std::string>{"!"};
    for (auto _ : state)
    {
        ReplaceElement::TelexEncoding(v);
    }
}
BENCHMARK(BM_TelexEncoding);

BENCHMARK_MAIN();
