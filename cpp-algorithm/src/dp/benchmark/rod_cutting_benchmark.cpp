#include "rod_cutting.h"

#include <benchmark/benchmark.h>

static void BM_CutRod(benchmark::State& state)
{
    const auto price =
        std::map<int, int>{{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    for (auto _ : state)
    {
        RodCutting::CutRod(price, state.range(0));
    }
}

BENCHMARK(BM_CutRod)->DenseRange(1, 10, 1);

static void BM_MemoizedCutRod(benchmark::State& state)
{
    const auto price =
        std::map<int, int>{{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    for (auto _ : state)
    {
        RodCutting::MemoizedCutRod(price, state.range(0));
    }
}

BENCHMARK(BM_MemoizedCutRod)->DenseRange(1, 10, 1);

static void BM_BottomUpCutRod(benchmark::State& state)
{
    const auto price =
        std::map<int, int>{{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    for (auto _ : state)
    {
        RodCutting::BottomUpCutRod(price, state.range(0));
    }
}

BENCHMARK(BM_BottomUpCutRod)->DenseRange(1, 10, 1);

static void BM_ExtendedBottomUpCutRod(benchmark::State& state)
{
    const auto price =
        std::map<int, int>{{1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    for (auto _ : state)
    {
        RodCutting::ExtendedBottomUpCutRod(price, state.range(0));
    }
}

BENCHMARK(BM_ExtendedBottomUpCutRod)->DenseRange(1, 10, 1);

BENCHMARK_MAIN();
