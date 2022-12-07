#include "convert_string.h"

#include <benchmark/benchmark.h>

static void BM_IntToString(benchmark::State& state)
{
    for (auto _ : state)
    {
        ConvertString::IntToString(state.range(0));
    }
}
BENCHMARK(BM_IntToString)->Arg(423)->Arg(314);

template <class... Args>
static void BM_StringToInt(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        ConvertString::StringToInt(std::get<0>(args_tuple));
    }
}
BENCHMARK_CAPTURE(BM_StringToInt, 423, "423");
BENCHMARK_CAPTURE(BM_StringToInt, 314, "314");

BENCHMARK_MAIN();
