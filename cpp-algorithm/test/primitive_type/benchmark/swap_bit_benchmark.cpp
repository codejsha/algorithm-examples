#include "swap_bit.h"

#include <benchmark/benchmark.h>

static void BM_SwapBits(benchmark::State& state)
{
    for (auto _ : state)
    {
        SwapBit::SwapBits(state.range(0), state.range(1), state.range(2));
    }
}
BENCHMARK(BM_SwapBits)->Args({0b01001001, 1, 6});

BENCHMARK_MAIN();
