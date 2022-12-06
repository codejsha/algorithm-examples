#include "replace_element.h"

#include <benchmark/benchmark.h>

static void BmReplaceAndRemoveString1(benchmark::State& state)
{
    auto arr = std::vector<std::string>{"a", "c", "d", "b", "b", "c", "a"};
    for (auto _ : state)
    {
        ReplaceElement::ReplaceAndRemoveString1(arr, "a", "b");
    }
}
BENCHMARK(BmReplaceAndRemoveString1);

static void BmReplaceAndRemoveString2(benchmark::State& state)
{
    auto arr = std::vector<std::string>{"a", "c", "d", "b", "b", "c", "a"};
    for (auto _ : state)
    {
        ReplaceElement::ReplaceAndRemoveString2(arr, "a", "b");
    }
}
BENCHMARK(BmReplaceAndRemoveString2);

static void BmTelexEncoding(benchmark::State& state)
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
BENCHMARK(BmTelexEncoding);

BENCHMARK_MAIN();
