#include "binary_tree.h"
#include "lowest_common_ancestor.h"

#include <gtest/gtest.h>

GTEST_TEST(LowestCommonAncestor, FindLowestCommonAncestor)
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

    EXPECT_EQ(&node1, LowestCommonAncestor::FindLowestCommonAncestor(&node1, &node2, &node3));
    EXPECT_EQ(&node1, LowestCommonAncestor::FindLowestCommonAncestor(&node1, &node4, &node6));
    EXPECT_EQ(&node2, LowestCommonAncestor::FindLowestCommonAncestor(&node1, &node8, &node11));
    EXPECT_EQ(&node3, LowestCommonAncestor::FindLowestCommonAncestor(&node1, &node6, &node7));
}

GTEST_TEST(LowestCommonAncestor, FindLowestCommonAncestor2)
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

    auto node1 = BinarySearchTree::Node{15};
    auto node2 = BinarySearchTree::Node{6};
    auto node3 = BinarySearchTree::Node{18};
    auto node4 = BinarySearchTree::Node{3};
    auto node5 = BinarySearchTree::Node{7};
    auto node6 = BinarySearchTree::Node{17};
    auto node7 = BinarySearchTree::Node{20};
    auto node8 = BinarySearchTree::Node{2};
    auto node9 = BinarySearchTree::Node{4};
    auto node10 = BinarySearchTree::Node{13};
    auto node11 = BinarySearchTree::Node{9};
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

    EXPECT_EQ(&node1, LowestCommonAncestor::FindLowestCommonAncestor2(&node1, &node2, &node3));
    EXPECT_EQ(&node1, LowestCommonAncestor::FindLowestCommonAncestor2(&node1, &node4, &node6));
    EXPECT_EQ(&node2, LowestCommonAncestor::FindLowestCommonAncestor2(&node1, &node8, &node11));
    EXPECT_EQ(&node3, LowestCommonAncestor::FindLowestCommonAncestor2(&node1, &node6, &node7));
}
