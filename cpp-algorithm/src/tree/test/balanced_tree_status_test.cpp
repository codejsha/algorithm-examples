#include "balanced_tree_status.h"
#include "binary_search_tree.h"

#include <gtest/gtest.h>

GTEST_TEST(BalancedTree, IsBalanced_1)
{
    // example tree:
    //             15
    //        /          \
    //      6              18
    //    /    \         /    \
    //   3      7       17     20
    //  /  \     \
    // 2    4     13
    //           /
    //          9

    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = BinarySearchTree::Tree<int>{};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    EXPECT_FALSE(BalancedTree::IsBalanced(tree.GetRoot()));
}

GTEST_TEST(BalancedTree, IsBalanced_2)
{
    // example tree:
    //             15
    //        /          \
    //      6              18
    //    /    \         /    \
    //   3      7       17     20
    //  /  \     \
    // 2    4     13

    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13};

    auto tree = BinarySearchTree::Tree<int>{};
    for (const int key : keys)
    {
        tree.Insert(key);
    }

    EXPECT_TRUE(BalancedTree::IsBalanced(tree.GetRoot()));
}
