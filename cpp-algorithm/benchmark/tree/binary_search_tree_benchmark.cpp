#include "binary_search_tree.h"

#include <benchmark/benchmark.h>

static void BM_BinarySearchTree_PreorderTraversal(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    auto result = std::vector<int>{};
    for (auto _ : state)
    {
        tree.PreorderTraversal(tree.GetRoot(), result);
    }
}
BENCHMARK(BM_BinarySearchTree_PreorderTraversal)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_InorderTraversal(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    auto result = std::vector<int>{};
    for (auto _ : state)
    {
        tree.PreorderTraversal(tree.GetRoot(), result);
    }
}
BENCHMARK(BM_BinarySearchTree_InorderTraversal)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_PostorderTraversal(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    auto result = std::vector<int>{};
    for (auto _ : state)
    {
        tree.PreorderTraversal(tree.GetRoot(), result);
    }
}
BENCHMARK(BM_BinarySearchTree_PostorderTraversal)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_Minimum(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Minimum(tree.GetRoot());
    }
}
BENCHMARK(BM_BinarySearchTree_Minimum)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_Maximum(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Minimum(tree.GetRoot());
    }
}
BENCHMARK(BM_BinarySearchTree_Maximum)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_Predecessor(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Minimum(tree.GetRoot());
    }
}
BENCHMARK(BM_BinarySearchTree_Predecessor)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_Successor(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.Minimum(tree.GetRoot());
    }
}
BENCHMARK(BM_BinarySearchTree_Successor)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_IterativeSearch(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.IterativeSearch(tree.GetRoot(), keys.back());
    }
}
BENCHMARK(BM_BinarySearchTree_IterativeSearch)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

static void BM_BinarySearchTree_RecursiveSearch(benchmark::State& state)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto _ : state)
    {
        tree.RecursiveSearch(tree.GetRoot(), keys.back());
    }
}
BENCHMARK(BM_BinarySearchTree_RecursiveSearch)->Args({15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9});

BENCHMARK_MAIN();
