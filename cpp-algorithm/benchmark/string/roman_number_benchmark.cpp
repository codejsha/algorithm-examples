#include "roman_number.h"

#include <benchmark/benchmark.h>

template <class... Args>
static void BM_VerifyRomanString(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        RomanNumber::VerifyRomanString(std::get<0>(args_tuple));
    }
}
BENCHMARK_CAPTURE(BM_VerifyRomanString, IXC, "IXC");
BENCHMARK_CAPTURE(BM_VerifyRomanString, CDM, "CDM");

template <class... Args>
static void BM_RomanStringToInteger(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        RomanNumber::RomanStringToInteger(std::get<0>(args_tuple));
    }
}
BENCHMARK_CAPTURE(BM_RomanStringToInteger, LIX, "LIX");

BENCHMARK_MAIN();
