#include "list_arithmetic_operation.h"

#include <benchmark/benchmark.h>

static void BM_AddTwoNumbers(benchmark::State& state)
{
    auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_a3});
    auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_a2});

    auto node_b3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{9, nullptr});
    auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node_b3});
    auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node_b2});

    for (auto _ : state)
    {
        ListArithmetic::AddTwoNumbers(node_a1, node_b1);
    }
}
BENCHMARK(BM_AddTwoNumbers);

BENCHMARK_MAIN();
