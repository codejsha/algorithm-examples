#include "red_black_tree.h"

#include <gtest/gtest.h>

TEST(RedBlackTreeTest, GetMinimum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected_value = *std::ranges::min_element(seq);

    auto tree = redblack::RedBlackTree{};
    for (const auto& element : seq)
    {
        auto node = redblack::RedBlackNode(element);
        tree.Insert(&tree, &node);
    }
}

TEST(RedBlackTreeTest, GetMaximum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected_value = *std::ranges::min_element(seq);

    auto tree = redblack::RedBlackTree{};
    const auto null_node = tree.GetNullNode();
    for (const auto& element : seq)
    {
        auto redblack_node = redblack::RedBlackNode(element, redblack::Red, null_node, null_node, null_node);
        tree.Insert(&tree, &redblack_node);
    }

    const auto result = tree.GetMaximum(tree.GetRootNode());

    ASSERT_EQ(expected_value, result->value);
}
