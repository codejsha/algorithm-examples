#include "reverse_list.h"

#include <benchmark/benchmark.h>

static void BM_ReverseSubList(benchmark::State& state)
{
    const auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node5});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, node2});

    for (auto _ : state)
    {
        ReverseList::ReverseSubList(node1, 2, 4);
    }
}

BENCHMARK(BM_ReverseSubList);

BENCHMARK_MAIN();
