#include "order_list_node.h"

#include <benchmark/benchmark.h>

static void BM_ListPivoting(benchmark::State& state)
{
    auto node7 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, nullptr});
    auto node6 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node7});
    auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node6});
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, node5});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    for (auto _ : state)
    {
        OrderListNode::ListPivoting(node1, 7);
    }
}
BENCHMARK(BM_ListPivoting);

BENCHMARK_MAIN();
