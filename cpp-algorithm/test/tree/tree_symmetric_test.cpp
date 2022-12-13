#include "binary_tree.h"
#include "tree_symmetric.h"

#include <gtest/gtest.h>

GTEST_TEST(TreeSymmetric, IsSymmetric_1)
{
    auto node_a = BinaryTree::Node{314};
    auto node_b = BinaryTree::Node{6};
    auto node_c = BinaryTree::Node{2};
    auto node_d = BinaryTree::Node{3};
    auto node_e = BinaryTree::Node{6};
    auto node_f = BinaryTree::Node{2};
    auto node_g = BinaryTree::Node{3};
    node_a.left = &node_b;
    node_a.right = &node_e;
    node_b.right = &node_c;
    node_c.right = &node_d;
    node_e.left = &node_f;
    node_f.left = &node_g;

    EXPECT_TRUE(TreeSymmetric::IsSymmetric(&node_a));
}

GTEST_TEST(TreeSymmetric, IsSymmetric_2)
{
    auto node_a = BinaryTree::Node{314};
    auto node_b = BinaryTree::Node{6};
    auto node_c = BinaryTree::Node{561};
    auto node_d = BinaryTree::Node{3};
    auto node_e = BinaryTree::Node{6};
    auto node_f = BinaryTree::Node{2};
    auto node_g = BinaryTree::Node{1};
    node_a.left = &node_b;
    node_a.right = &node_e;
    node_b.right = &node_c;
    node_c.right = &node_d;
    node_e.left = &node_f;
    node_f.left = &node_g;

    EXPECT_FALSE(TreeSymmetric::IsSymmetric(&node_a));
}

GTEST_TEST(TreeSymmetric, IsSymmetric_3)
{
    auto node_a = BinaryTree::Node{314};
    auto node_b = BinaryTree::Node{6};
    auto node_c = BinaryTree::Node{561};
    auto node_d = BinaryTree::Node{3};
    auto node_e = BinaryTree::Node{6};
    auto node_f = BinaryTree::Node{561};
    node_a.left = &node_b;
    node_a.right = &node_e;
    node_b.right = &node_c;
    node_c.right = &node_d;
    node_e.left = &node_f;

    EXPECT_FALSE(TreeSymmetric::IsSymmetric(&node_a));
}
