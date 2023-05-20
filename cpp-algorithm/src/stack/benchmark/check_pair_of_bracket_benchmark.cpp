#include "check_pair_of_bracket.h"

#include <benchmark/benchmark.h>

template <class... Args>
static void BM_CheckPairOfBracket(benchmark::State& state, Args&&... args)
{
    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(PairOfBracket::CheckPairOfBracket(std::get<0>(args_tuple)));
    }
}

BENCHMARK_CAPTURE(BM_CheckPairOfBracket, ()[]{}, "()[]{}");
BENCHMARK_CAPTURE(BM_CheckPairOfBracket, ([]){()}, "([]){()}");
BENCHMARK_CAPTURE(BM_CheckPairOfBracket, [()[]{()()}], "[()[]{()()}]");
