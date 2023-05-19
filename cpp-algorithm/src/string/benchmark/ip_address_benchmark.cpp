#include "ip_address.h"

#include <benchmark/benchmark.h>

static void BM_GetValidIpAddress(benchmark::State& state)
{
    for (auto _ : state)
    {
        IpAddress::GetValidIpAddress("25525511135");
    }
}

BENCHMARK(BM_GetValidIpAddress);

BENCHMARK_MAIN();
