#include "list_palindrome.h"

#include <benchmark/benchmark.h>

static void BM_IsListPalindrome(benchmark::State& state)
{
    const auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node5});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});

    for (auto _ : state)
    {
        ListPalindrome::IsListPalindrome(node1);
    }
}
BENCHMARK(BM_IsListPalindrome);

BENCHMARK_MAIN();
