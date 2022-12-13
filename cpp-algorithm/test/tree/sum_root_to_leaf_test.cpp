#include "sum_root_to_leaf.h"

#include <gtest/gtest.h>

GTEST_TEST(SumRootToLeaf, SumRootToLeafDecimal)
{
    // example tree:
    //   1
    //  / \
    // 2   3

    auto node1 = BinaryTree::Node{1};
    auto node2 = BinaryTree::Node{2};
    auto node3 = BinaryTree::Node{3};
    node1.left = &node2;
    node1.right = &node3;

    constexpr auto expected = 25;
    const auto result = TreeSumRootToLeaf::SumRootToLeafDecimal(&node1);

    EXPECT_EQ(expected, result);
}

GTEST_TEST(SumRootToLeaf, SumRootToLeafBinary)
{
    // example tree:
    //        a1
    //     /      \
    //   b0        c1
    //  /  \      /  \
    // d0   e1   f0   g1

    auto node_a = BinaryTree::Node{1};
    auto node_b = BinaryTree::Node{0};
    auto node_c = BinaryTree::Node{1};
    auto node_d = BinaryTree::Node{0};
    auto node_e = BinaryTree::Node{1};
    auto node_f = BinaryTree::Node{0};
    auto node_g = BinaryTree::Node{1};
    node_a.left = &node_b;
    node_a.right = &node_c;
    node_b.left = &node_d;
    node_b.right = &node_e;
    node_c.left = &node_f;
    node_c.right = &node_g;

    constexpr auto expected = 0b10110;
    const auto result = TreeSumRootToLeaf::SumRootToLeafBinary(&node_a);

    EXPECT_EQ(expected, result);
}
