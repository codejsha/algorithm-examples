#include "compute_parity.h"

#include <benchmark/benchmark.h>

static void BM_CountBits(benchmark::State& state)
{
    for (auto _ : state)
    {
        ComputingParity::CountBits(state.range(0));
    }
}
BENCHMARK(BM_CountBits)->Arg(0b1011)->Arg(0b10001000);

static void BM_Parity(benchmark::State& state)
{
    for (auto _ : state)
    {
        ComputingParity::Parity(state.range(0));
    }
}
BENCHMARK(BM_Parity)->Arg(0b1011)->Arg(0b10001000);

static void BM_ParityDropLowestBits(benchmark::State& state)
{
    for (auto _ : state)
    {
        ComputingParity::ParityDropLowestBits(state.range(0));
    }
}
BENCHMARK(BM_ParityDropLowestBits)->Arg(0b1011)->Arg(0b10001000);

static void BM_ParityLookupTable(benchmark::State& state)
{
    for (auto _ : state)
    {
        ComputingParity::ParityLookupTable(state.range(0));
    }
}
BENCHMARK(BM_ParityLookupTable)->Arg(0b11101010);

BENCHMARK_MAIN();
