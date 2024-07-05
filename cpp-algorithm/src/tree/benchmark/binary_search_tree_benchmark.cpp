#include "binary_search_tree.h"

#include <benchmark/benchmark.h>

static void BM_BinarySearchTree_PreorderTraversal(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    std::vector<int> result;
    for (auto _ : state)
    {
        tree.PreorderTraversal(tree.GetRoot(), result);
    }
}

BENCHMARK(BM_BinarySearchTree_PreorderTraversal);

static void BM_BinarySearchTree_InorderTraversal(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    std::vector<int> result;
    for (auto _ : state)
    {
        tree.PreorderTraversal(tree.GetRoot(), result);
    }
}

BENCHMARK(BM_BinarySearchTree_InorderTraversal);

static void BM_BinarySearchTree_PostorderTraversal(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    std::vector<int> result;
    for (auto _ : state)
    {
        tree.PreorderTraversal(tree.GetRoot(), result);
    }
}

BENCHMARK(BM_BinarySearchTree_PostorderTraversal);

static void BM_BinarySearchTree_Minimum(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Minimum(tree.GetRoot());
    }
}

BENCHMARK(BM_BinarySearchTree_Minimum);

static void BM_BinarySearchTree_Maximum(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Maximum(tree.GetRoot());
    }
}

BENCHMARK(BM_BinarySearchTree_Maximum);

static void BM_BinarySearchTree_Predecessor(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Predecessor(state.range(0));
    }
}

BENCHMARK(BM_BinarySearchTree_Predecessor)
    ->Arg(15)
    ->Arg(6)
    ->Arg(18)
    ->Arg(3)
    ->Arg(7)
    ->Arg(17)
    ->Arg(20)
    ->Arg(2)
    ->Arg(4)
    ->Arg(13)
    ->Arg(9);

static void BM_BinarySearchTree_Successor(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Successor(state.range(0));
    }
}

BENCHMARK(BM_BinarySearchTree_Successor)
    ->Arg(15)
    ->Arg(6)
    ->Arg(18)
    ->Arg(3)
    ->Arg(7)
    ->Arg(17)
    ->Arg(20)
    ->Arg(2)
    ->Arg(4)
    ->Arg(13)
    ->Arg(9);

static void BM_BinarySearchTree_IterativeSearch(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.IterativeSearch(tree.GetRoot(), state.range(0));
    }
}

BENCHMARK(BM_BinarySearchTree_IterativeSearch)
    ->Arg(15)
    ->Arg(6)
    ->Arg(18)
    ->Arg(3)
    ->Arg(7)
    ->Arg(17)
    ->Arg(20)
    ->Arg(2)
    ->Arg(4)
    ->Arg(13)
    ->Arg(9);

static void BM_BinarySearchTree_RecursiveSearch(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.RecursiveSearch(tree.GetRoot(), state.range(0));
    }
}

BENCHMARK(BM_BinarySearchTree_RecursiveSearch)
    ->Arg(15)
    ->Arg(6)
    ->Arg(18)
    ->Arg(3)
    ->Arg(7)
    ->Arg(17)
    ->Arg(20)
    ->Arg(2)
    ->Arg(4)
    ->Arg(13)
    ->Arg(9);

BENCHMARK_MAIN();
