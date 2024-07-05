#include "b_tree.h"

#include <gtest/gtest.h>

GTEST_TEST(BTree, Insert)
{
    // example tree:
    //             (G      M      P      X)
    //           /      /      |     \        \
    //          /      /       |      \        \
    // (A C D E)   (J K)    (N O)  (R S T U V)  (Y Z)

    auto root_node = new BTree::Node{};
    root_node->keys = {'G', 'M', 'P', 'X'};
    root_node->is_leaf = false;

    auto child_node1 = new BTree::Node{};
    child_node1->keys = {'A', 'C', 'D', 'E'};
    child_node1->is_leaf = true;

    auto child_node2 = new BTree::Node{};
    child_node2->keys = {'J', 'K'};
    child_node2->is_leaf = true;

    auto child_node3 = new BTree::Node{};
    child_node3->keys = {'N', 'O'};
    child_node3->is_leaf = true;

    auto child_node4 = new BTree::Node{};
    child_node4->keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->is_leaf = true;

    auto child_node5 = new BTree::Node{};
    child_node5->keys = {'Y', 'Z'};
    child_node5->is_leaf = true;

    root_node->children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = BTree::Tree{};
    tree.root = root_node;
    tree.degree = 3;

    // insert B:
    //            (G      M      P      X)
    //          /      /      |     \        \
    //         /      /       |      \        \
    // (a b c d e)  (J K)   (N O)  (R S T U V)  (Y Z)

    tree.Insert(tree.root, 'B');
    auto expected_b = std::vector{'G', 'M', 'P', 'X'};
    auto expected_b0 = std::vector{'A', 'B', 'C', 'D', 'E'};
    auto expected_b1 = std::vector{'J', 'K'};
    auto expected_b2 = std::vector{'N', 'O'};
    auto expected_b3 = std::vector{'R', 'S', 'T', 'U', 'V'};
    auto expected_b4 = std::vector{'Y', 'Z'};
    ASSERT_EQ(expected_b, tree.root->keys);
    ASSERT_EQ(expected_b0, tree.root->children[0]->keys);
    ASSERT_EQ(expected_b1, tree.root->children[1]->keys);
    ASSERT_EQ(expected_b2, tree.root->children[2]->keys);
    ASSERT_EQ(expected_b3, tree.root->children[3]->keys);
    ASSERT_EQ(expected_b4, tree.root->children[4]->keys);

    // insert Q:
    //           (g      m      p      t     x)
    //        /       /      |      \      \      \
    //       /       /       |       \      \      \
    // (A B C D E)  (J K)   (N O)  (q r s)  (u v)  (Y Z)

    tree.Insert(tree.root, 'Q');
    auto expected_q = std::vector{'G', 'M', 'P', 'T', 'X'};
    auto expected_q0 = std::vector{'A', 'B', 'C', 'D', 'E'};
    auto expected_q1 = std::vector{'J', 'K'};
    auto expected_q2 = std::vector{'N', 'O'};
    auto expected_q3 = std::vector{'Q', 'R', 'S'};
    auto expected_q4 = std::vector{'U', 'V'};
    auto expected_q5 = std::vector{'Y', 'Z'};
    ASSERT_EQ(expected_q, tree.root->keys);
    ASSERT_EQ(expected_q0, tree.root->children[0]->keys);
    ASSERT_EQ(expected_q1, tree.root->children[1]->keys);
    ASSERT_EQ(expected_q2, tree.root->children[2]->keys);
    ASSERT_EQ(expected_q3, tree.root->children[3]->keys);
    ASSERT_EQ(expected_q4, tree.root->children[4]->keys);
    ASSERT_EQ(expected_q5, tree.root->children[5]->keys);

    // insert L:
    //                         (p)
    //                /                   \
    //               /                     \
    //            (g   m)                (t   x)
    //          /    |    \             /   |   \
    //         /     |     \           /    |    \
    // (A B C D E) (j k l) (N O)   (Q R S) (U V) (Y Z)

    tree.Insert(tree.root, 'L');
    auto expected_l = std::vector{'P'};
    auto expected_l0 = std::vector{'G', 'M'};
    auto expected_l00 = std::vector{'A', 'B', 'C', 'D', 'E'};
    auto expected_l01 = std::vector{'J', 'K', 'L'};
    auto expected_l02 = std::vector{'N', 'O'};
    auto expected_l1 = std::vector{'T', 'X'};
    auto expected_l10 = std::vector{'Q', 'R', 'S'};
    auto expected_l11 = std::vector{'U', 'V'};
    auto expected_l12 = std::vector{'Y', 'Z'};
    ASSERT_EQ(expected_l, tree.root->keys);
    ASSERT_EQ(expected_l0, tree.root->children[0]->keys);
    ASSERT_EQ(expected_l00, tree.root->children[0]->children[0]->keys);
    ASSERT_EQ(expected_l01, tree.root->children[0]->children[1]->keys);
    ASSERT_EQ(expected_l02, tree.root->children[0]->children[2]->keys);
    ASSERT_EQ(expected_l1, tree.root->children[1]->keys);
    ASSERT_EQ(expected_l10, tree.root->children[1]->children[0]->keys);
    ASSERT_EQ(expected_l11, tree.root->children[1]->children[1]->keys);
    ASSERT_EQ(expected_l12, tree.root->children[1]->children[2]->keys);

    // insert F:
    //                            (P)
    //                  /                     \
    //                 /                       \
    //          (c    g    m)                 (T   X)
    //        /    /     \     \             /   |   \
    //       /    /       \     \           /    |    \
    // (a b c) (d e f) (J K L) (N O)   (Q R S) (U V) (Y Z)

    tree.Insert(tree.root, 'F');
    auto expected_f = std::vector{'P'};
    auto expected_f0 = std::vector{'C', 'G', 'M'};
    auto expected_f00 = std::vector{'A', 'B'};
    auto expected_f01 = std::vector{'D', 'E', 'F'};
    auto expected_f02 = std::vector{'J', 'K', 'L'};
    auto expected_f03 = std::vector{'N', 'O'};
    auto expected_f1 = std::vector{'T', 'X'};
    auto expected_f10 = std::vector{'Q', 'R', 'S'};
    auto expected_f11 = std::vector{'U', 'V'};
    auto expected_f12 = std::vector{'Y', 'Z'};
    ASSERT_EQ(expected_l, tree.root->keys);
    ASSERT_EQ(expected_f0, tree.root->children[0]->keys);
    ASSERT_EQ(expected_f00, tree.root->children[0]->children[0]->keys);
    ASSERT_EQ(expected_f01, tree.root->children[0]->children[1]->keys);
    ASSERT_EQ(expected_f02, tree.root->children[0]->children[2]->keys);
    ASSERT_EQ(expected_f03, tree.root->children[0]->children[3]->keys);
    ASSERT_EQ(expected_f1, tree.root->children[1]->keys);
    ASSERT_EQ(expected_f10, tree.root->children[1]->children[0]->keys);
    ASSERT_EQ(expected_f11, tree.root->children[1]->children[1]->keys);
    ASSERT_EQ(expected_f12, tree.root->children[1]->children[2]->keys);
}

GTEST_TEST(BTree, Search)
{
    // example tree:
    //                            (P)
    //                  /                     \
    //                 /                       \
    //          (C    G    M)                 (T   X)
    //        /    /     \     \             /   |   \
    //       /    /       \     \           /    |    \
    // (A B C) (D E F) (J K L) (N O)   (Q R S) (U V) (Y Z)

    auto root_node = new BTree::Node{};
    root_node->keys = {'G', 'M', 'P', 'X'};
    root_node->is_leaf = false;

    auto child_node1 = new BTree::Node{};
    child_node1->keys = {'A', 'C', 'D', 'E'};
    child_node1->is_leaf = true;

    auto child_node2 = new BTree::Node{};
    child_node2->keys = {'J', 'K'};
    child_node2->is_leaf = true;

    auto child_node3 = new BTree::Node{};
    child_node3->keys = {'N', 'O'};
    child_node3->is_leaf = true;

    auto child_node4 = new BTree::Node{};
    child_node4->keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->is_leaf = true;

    auto child_node5 = new BTree::Node{};
    child_node5->keys = {'Y', 'Z'};
    child_node5->is_leaf = true;

    root_node->children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = BTree::Tree{};
    tree.root = root_node;
    tree.degree = 3;

    tree.Insert(tree.root, 'B');
    tree.Insert(tree.root, 'Q');
    tree.Insert(tree.root, 'L');
    tree.Insert(tree.root, 'F');

    // search B
    constexpr char ch1 = 'B';
    auto [node1, key1] = tree.Search(tree.root, ch1);
    const char result_key1 = node1->keys[key1];
    ASSERT_EQ(ch1, result_key1);

    // search Q
    constexpr char ch2 = 'Q';
    auto [node2, key2] = tree.Search(tree.root, ch2);
    const char result_key2 = node2->keys[key2];
    ASSERT_EQ(ch2, result_key2);

    // search L
    constexpr char ch3 = 'L';
    auto [node3, key3] = tree.Search(tree.root, ch3);
    const char result_key3 = node3->keys[key3];
    ASSERT_EQ(ch3, result_key3);

    // search F
    constexpr char ch4 = 'F';
    auto [node4, key4] = tree.Search(tree.root, ch4);
    const char result_key4 = node4->keys[key4];
    ASSERT_EQ(ch4, result_key4);
}
