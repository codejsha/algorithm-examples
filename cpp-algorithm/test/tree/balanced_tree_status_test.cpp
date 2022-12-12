#include "binary_search_tree.h"
#include "balanced_tree_status.h"

#include <gtest/gtest.h>

GTEST_TEST(BalancedTreeStatusTest, IsBalanced_1)
{
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = BinarySearchTree::Tree<int>{};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    EXPECT_FALSE(BalancedTree::IsBalanced(tree.GetRoot()));
}

GTEST_TEST(BalancedTreeStatusTest, IsBalanced_2)
{
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13};

    auto tree = BinarySearchTree::Tree<int>{};
    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    EXPECT_TRUE(BalancedTree::IsBalanced(tree.GetRoot()));
}
