#include "b_tree.h"

#include <benchmark/benchmark.h>

template <class... Args>
static void BM_BTree_Insert(benchmark::State& state, Args&&... args)
{
    auto root_node = new BTree::Node<char>();
    root_node->keys = {'G', 'M', 'P', 'X'};
    root_node->is_leaf = false;

    auto child_node1 = new BTree::Node<char>();
    child_node1->keys = {'A', 'C', 'D', 'E'};
    child_node1->is_leaf = true;

    auto child_node2 = new BTree::Node<char>();
    child_node2->keys = {'J', 'K'};
    child_node2->is_leaf = true;

    auto child_node3 = new BTree::Node<char>();
    child_node3->keys = {'N', 'O'};
    child_node3->is_leaf = true;

    auto child_node4 = new BTree::Node<char>();
    child_node4->keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->is_leaf = true;

    auto child_node5 = new BTree::Node<char>();
    child_node5->keys = {'Y', 'Z'};
    child_node5->is_leaf = true;

    root_node->children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = BTree::Tree<char>{};
    tree.SetRoot(root_node);
    tree.SetDegree(3);

    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        tree.Insert(tree.GetRoot(), std::get<0>(args_tuple));
    }
}
BENCHMARK_CAPTURE(BM_BTree_Insert, B, 'B');
BENCHMARK_CAPTURE(BM_BTree_Insert, Q, 'Q');
BENCHMARK_CAPTURE(BM_BTree_Insert, L, 'L');
BENCHMARK_CAPTURE(BM_BTree_Insert, F, 'F');

template <class... Args>
static void BM_BTree_Search(benchmark::State& state, Args&&... args)
{
    auto root_node = new BTree::Node<char>();
    root_node->keys = {'G', 'M', 'P', 'X'};
    root_node->is_leaf = false;

    auto child_node1 = new BTree::Node<char>();
    child_node1->keys = {'A', 'C', 'D', 'E'};
    child_node1->is_leaf = true;

    auto child_node2 = new BTree::Node<char>();
    child_node2->keys = {'J', 'K'};
    child_node2->is_leaf = true;

    auto child_node3 = new BTree::Node<char>();
    child_node3->keys = {'N', 'O'};
    child_node3->is_leaf = true;

    auto child_node4 = new BTree::Node<char>();
    child_node4->keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->is_leaf = true;

    auto child_node5 = new BTree::Node<char>();
    child_node5->keys = {'Y', 'Z'};
    child_node5->is_leaf = true;

    root_node->children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = BTree::Tree<char>{};
    tree.SetRoot(root_node);
    tree.SetDegree(3);

    tree.Insert(tree.GetRoot(), 'B');
    tree.Insert(tree.GetRoot(), 'Q');
    tree.Insert(tree.GetRoot(), 'L');
    tree.Insert(tree.GetRoot(), 'F');

    auto args_tuple = std::make_tuple(std::move(args)...);
    for (auto _ : state)
    {
        tree.Search(tree.GetRoot(), std::get<0>(args_tuple));
    }
}
BENCHMARK_CAPTURE(BM_BTree_Search, B, 'B');
BENCHMARK_CAPTURE(BM_BTree_Search, Q, 'Q');
BENCHMARK_CAPTURE(BM_BTree_Search, L, 'L');
BENCHMARK_CAPTURE(BM_BTree_Search, F, 'F');

BENCHMARK_MAIN();
