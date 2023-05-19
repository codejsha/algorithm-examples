#include "run_length_encoding.h"

#include <benchmark/benchmark.h>

template <class... Args>
static void BM_RunLengthEncoding(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        RunLengthEncoding::RunLengthEncoding(std::get<0>(args_tuple));
    }
}

BENCHMARK_CAPTURE(BM_RunLengthEncoding, aaaabcccaa, "aaaabcccaa");
BENCHMARK_CAPTURE(BM_RunLengthEncoding, eeeffffee, "eeeffffee");

template <class... Args>
static void BM_RunLengthDecoding(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        RunLengthEncoding::RunLengthDecoding(std::get<0>(args_tuple));
    }
}

BENCHMARK_CAPTURE(BM_RunLengthDecoding, 4a1b3c2a, "4a1b3c2a");
BENCHMARK_CAPTURE(BM_RunLengthDecoding, 3e4f2e, "3e4f2e");

BENCHMARK_MAIN();
