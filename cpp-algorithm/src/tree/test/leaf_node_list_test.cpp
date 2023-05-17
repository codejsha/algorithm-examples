#include "leaf_node_list.h"

#include <gtest/gtest.h>

GTEST_TEST(LeafNodeList, CreateLeafNodeList)
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

    const auto expected = std::vector{2, 4, 9, 17, 20};
    const auto result = LeafNodeList::CreateLeafNodeList(&node1);
    auto result_values = std::vector<int>{};
    for (const auto& node : result)
    {
        result_values.push_back(node->key);
    }
    EXPECT_EQ(expected, result_values);
}
