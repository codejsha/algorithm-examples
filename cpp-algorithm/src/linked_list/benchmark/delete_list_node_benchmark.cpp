#include "delete_list_node.h"

#include <benchmark/benchmark.h>

static void BM_DeleteNodeFromList(benchmark::State& state)
{
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    for (auto _ : state)
    {
        DeleteListNode::DeleteNodeFromList(node3);
    }
}
BENCHMARK(BM_DeleteNodeFromList);

static void BM_DeleteNodeKthLast(benchmark::State& state)
{
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    for (auto _ : state)
    {
        DeleteListNode::DeleteNodeKthLast(node1, 2);
    }
}
BENCHMARK(BM_DeleteNodeKthLast);

static void BM_DeleteDuplicateNode(benchmark::State& state)
{
    auto node7 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, nullptr});
    auto node6 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, node7});
    auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node6});
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node5});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node2});

    for (auto _ : state)
    {
        DeleteListNode::DeleteNodeKthLast(node1, 2);
    }
}
BENCHMARK(BM_DeleteDuplicateNode);

BENCHMARK_MAIN();
