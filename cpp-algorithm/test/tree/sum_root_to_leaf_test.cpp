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

GTEST_TEST(SumRootToLeaf, HasKeySum)
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

    auto node1 = BinaryTree::Node{15};
    auto node2 = BinaryTree::Node{6};
    auto node3 = BinaryTree::Node{18};
    auto node4 = BinaryTree::Node{3};
    auto node5 = BinaryTree::Node{7};
    auto node6 = BinaryTree::Node{17};
    auto node7 = BinaryTree::Node{20};
    auto node8 = BinaryTree::Node{2};
    auto node9 = BinaryTree::Node{4};
    auto node10 = BinaryTree::Node{13};
    auto node11 = BinaryTree::Node{9};
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = &node8;
    node4.right = &node9;
    node5.right = &node10;
    node10.left = &node11;

    EXPECT_TRUE(TreeSumRootToLeaf::HasKeySum(&node1, 26));
    EXPECT_TRUE(TreeSumRootToLeaf::HasKeySum(&node1, 28));
    EXPECT_TRUE(TreeSumRootToLeaf::HasKeySum(&node1, 50));
    EXPECT_TRUE(TreeSumRootToLeaf::HasKeySum(&node1, 53));

    EXPECT_FALSE(TreeSumRootToLeaf::HasKeySum(&node1, 16));
    EXPECT_FALSE(TreeSumRootToLeaf::HasKeySum(&node1, 20));
    EXPECT_FALSE(TreeSumRootToLeaf::HasKeySum(&node1, 33));
    EXPECT_FALSE(TreeSumRootToLeaf::HasKeySum(&node1, 41));
    EXPECT_FALSE(TreeSumRootToLeaf::HasKeySum(&node1, 94));
}
