#include "merge_list.h"

#include <benchmark/benchmark.h>

static void BM_MergeTwoSortedLinkedList(benchmark::State& state)
{
    const auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    const auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_a3});
    const auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_a2});

    const auto node_b3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    const auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_b3});
    const auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_b2});

    for (auto _ : state)
    {
        MergeList::MergeTwoSortedLinkedList(node_a1, node_b1);
    }
}
BENCHMARK(BM_MergeTwoSortedLinkedList);

static void BM_MergeEvenOddLinkedList(benchmark::State& state)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    for (auto _ : state)
    {
        MergeList::MergeEvenOddLinkedList(node1);
    }
}
BENCHMARK(BM_MergeEvenOddLinkedList);

BENCHMARK_MAIN();
