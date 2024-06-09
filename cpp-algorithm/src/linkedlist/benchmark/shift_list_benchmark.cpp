#include "shift_list.h"

#include <benchmark/benchmark.h>

static void BM_CyclicallyRightShiftList(benchmark::State& state)
{
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    for (auto _ : state)
    {
        ShiftList::CyclicallyRightShiftList(node1, 2);
    }
}

BENCHMARK(BM_CyclicallyRightShiftList);

BENCHMARK_MAIN();
