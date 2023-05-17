#include "palindrome.h"

#include <benchmark/benchmark.h>

template <class... Args>
static void BM_IsPalindromic1(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        Palindrome::IsPalindromic1(std::get<0>(args_tuple));
    }
}
BENCHMARK_CAPTURE(BM_IsPalindromic1, kayak, "kayak");
BENCHMARK_CAPTURE(BM_IsPalindromic1, deed, "deed");
BENCHMARK_CAPTURE(BM_IsPalindromic1, rotator, "rotator");
BENCHMARK_CAPTURE(BM_IsPalindromic1, noon, "noon");

template <class... Args>
static void BM_IsPalindromic2(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        Palindrome::IsPalindromic2(std::get<0>(args_tuple));
    }
}
BENCHMARK_CAPTURE(BM_IsPalindromic2, kayak, "kayak");
BENCHMARK_CAPTURE(BM_IsPalindromic2, deed, "deed");
BENCHMARK_CAPTURE(BM_IsPalindromic2, rotator, "rotator");
BENCHMARK_CAPTURE(BM_IsPalindromic2, noon, "noon");

BENCHMARK_MAIN();
