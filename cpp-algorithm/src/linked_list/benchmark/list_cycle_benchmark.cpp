#include "list_cycle.h"

#include <benchmark/benchmark.h>

static void BM_HasCycle1(benchmark::State& state)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    for (auto _ : state)
    {
        ListCycle::HasCycle1(node1);
    }
}
BENCHMARK(BM_HasCycle1);

static void BM_HasCycle2(benchmark::State& state)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    for (auto _ : state)
    {
        ListCycle::HasCycle2(node1);
    }
}
BENCHMARK(BM_HasCycle2);

static void BM_HasCycle3(benchmark::State& state)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    for (auto _ : state)
    {
        ListCycle::HasCycle2(node1);
    }
}
BENCHMARK(BM_HasCycle3);

static void BM_OverlappingNoCycleList(benchmark::State& state)
{
    auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, nullptr});
    auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node_a3});
    auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_a2});

    auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, nullptr});
    auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_b2});

    for (auto _ : state)
    {
        ListCycle::OverlappingNoCycleList(node_a1, node_b1);
    }
}
BENCHMARK(BM_OverlappingNoCycleList);

static void BM_OverlappingCycleList(benchmark::State& state)
{
    auto node_a4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node_a4});
    auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_a3});
    auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_a2});
    node_a4->next = node_a2;

    auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_a3});
    auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_b2});

    for (auto _ : state)
    {
        ListCycle::OverlappingCycleList(node_a1, node_b1);
    }
}
BENCHMARK(BM_OverlappingCycleList);

BENCHMARK_MAIN();
