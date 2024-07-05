#include "binary_tree_exterior.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(BinaryTreeExterior, CreateExteriorNodeList)
{
    // example tree:
    //             A
    //        /          \
    //      B              C
    //    /    \         /    \
    //   D      E       F      G
    //  /  \     \
    // H    I     J
    //           /
    //          K

    auto node1 = BinaryTree::Node{'A'};
    auto node2 = BinaryTree::Node{'B'};
    auto node3 = BinaryTree::Node{'C'};
    auto node4 = BinaryTree::Node{'D'};
    auto node5 = BinaryTree::Node{'E'};
    auto node6 = BinaryTree::Node{'F'};
    auto node7 = BinaryTree::Node{'G'};
    auto node8 = BinaryTree::Node{'H'};
    auto node9 = BinaryTree::Node{'I'};
    auto node10 = BinaryTree::Node{'J'};
    auto node11 = BinaryTree::Node{'K'};
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

    const auto expected = std::vector{'A', 'B', 'D', 'H', 'I', 'K', 'F', 'G', 'C'};
    const auto result = BinaryTreeExterior::CreateExteriorNodeList(&node1);

    std::vector<char> result_values;
    for (const auto& node : result)
    {
        result_values.push_back(node->key);
    }
    EXPECT_EQ(expected, result_values);
}
