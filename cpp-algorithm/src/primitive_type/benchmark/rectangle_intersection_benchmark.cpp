#include "rectangle_intersection.h"

#include <benchmark/benchmark.h>

static void BM_IntersectRectangle(benchmark::State& state)
{
    constexpr auto rect1 = RectangleIntersection::Rectangle{1, 2, 3, 4};
    constexpr auto rect2 = RectangleIntersection::Rectangle{5, 3, 2, 4};
    for (auto _ : state)
    {
        IntersectRectangle(rect1, rect2);
    }
}

BENCHMARK(BM_IntersectRectangle);

BENCHMARK_MAIN();
