#include "optimized_lca.h"

#include <gtest/gtest.h>

GTEST_TEST(OptimizedLca, OptimizedLca)
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

    auto node1 = BinaryTree::ExtendedNode{15};
    auto node2 = BinaryTree::ExtendedNode{6};
    auto node3 = BinaryTree::ExtendedNode{18};
    auto node4 = BinaryTree::ExtendedNode{3};
    auto node5 = BinaryTree::ExtendedNode{7};
    auto node6 = BinaryTree::ExtendedNode{17};
    auto node7 = BinaryTree::ExtendedNode{20};
    auto node8 = BinaryTree::ExtendedNode{2};
    auto node9 = BinaryTree::ExtendedNode{4};
    auto node10 = BinaryTree::ExtendedNode{13};
    auto node11 = BinaryTree::ExtendedNode{9};
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node2.parent = &node1;
    node3.left = &node6;
    node3.right = &node7;
    node3.parent = &node1;
    node4.left = &node8;
    node4.right = &node9;
    node4.parent = &node2;
    node5.right = &node10;
    node5.parent = &node2;
    node6.parent = &node3;
    node7.parent = &node3;
    node8.parent = &node4;
    node9.parent = &node4;
    node10.left = &node11;
    node10.parent = &node5;
    node11.parent = &node10;

    EXPECT_EQ(&node1, OptimizedLca::FindOptimizedLowestCommonAncestor(&node2, &node3));
    EXPECT_EQ(&node1, OptimizedLca::FindOptimizedLowestCommonAncestor(&node4, &node6));
    EXPECT_EQ(&node2, OptimizedLca::FindOptimizedLowestCommonAncestor(&node8, &node11));
    EXPECT_EQ(&node3, OptimizedLca::FindOptimizedLowestCommonAncestor(&node6, &node7));
}
