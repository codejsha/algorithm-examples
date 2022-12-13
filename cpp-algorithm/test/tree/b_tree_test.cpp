#include "b_tree.h"

#include <gtest/gtest.h>

GTEST_TEST(BTree, Insert)
{
    // example tree:
    //             (G      M      P      X)
    //           /      /      |     \        \
    //          /      /       |      \        \
    // (A C D E)   (J K)    (N O)  (R S T U V)  (Y Z)

    auto root_node = new BTree::Node<char>();
    root_node->keys = {'G', 'M', 'P', 'X'};
    root_node->is_leaf = false;

    auto child_node1 = new BTree::Node<char>();
    child_node1->keys = {'A', 'C', 'D', 'E'};
    child_node1->is_leaf = true;

    auto child_node2 = new BTree::Node<char>();
    child_node2->keys = {'J', 'K'};
    child_node2->is_leaf = true;

    auto child_node3 = new BTree::Node<char>();
    child_node3->keys = {'N', 'O'};
    child_node3->is_leaf = true;

    auto child_node4 = new BTree::Node<char>();
    child_node4->keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->is_leaf = true;

    auto child_node5 = new BTree::Node<char>();
    child_node5->keys = {'Y', 'Z'};
    child_node5->is_leaf = true;

    root_node->children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = BTree::Tree<char>{};
    tree.SetRoot(root_node);
    tree.SetDegree(3);

    // insert B:
    //            (G      M      P      X)
    //          /      /      |     \        \
    //         /      /       |      \        \
    // (a b c d e)  (J K)   (N O)  (R S T U V)  (Y Z)

    tree.Insert(tree.GetRoot(),'B');
    auto expected_b = std::vector<char>{'G', 'M', 'P', 'X'};
    auto expected_b0 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    auto expected_b1 = std::vector<char>{'J', 'K'};
    auto expected_b2 = std::vector<char>{'N', 'O'};
    auto expected_b3 = std::vector<char>{'R', 'S', 'T', 'U', 'V'};
    auto expected_b4 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_b, tree.GetRoot()->keys);
    ASSERT_EQ(expected_b0, tree.GetRoot()->children[0]->keys);
    ASSERT_EQ(expected_b1, tree.GetRoot()->children[1]->keys);
    ASSERT_EQ(expected_b2, tree.GetRoot()->children[2]->keys);
    ASSERT_EQ(expected_b3, tree.GetRoot()->children[3]->keys);
    ASSERT_EQ(expected_b4, tree.GetRoot()->children[4]->keys);

    // insert Q:
    //           (g      m      p      t     x)
    //        /       /      |      \      \      \
    //       /       /       |       \      \      \
    // (A B C D E)  (J K)   (N O)  (q r s)  (u v)  (Y Z)

    tree.Insert(tree.GetRoot(), 'Q');
    auto expected_q = std::vector<char>{'G', 'M', 'P', 'T', 'X'};
    auto expected_q0 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    auto expected_q1 = std::vector<char>{'J', 'K'};
    auto expected_q2 = std::vector<char>{'N', 'O'};
    auto expected_q3 = std::vector<char>{'Q', 'R', 'S'};
    auto expected_q4 = std::vector<char>{'U', 'V'};
    auto expected_q5 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_q, tree.GetRoot()->keys);
    ASSERT_EQ(expected_q0, tree.GetRoot()->children[0]->keys);
    ASSERT_EQ(expected_q1, tree.GetRoot()->children[1]->keys);
    ASSERT_EQ(expected_q2, tree.GetRoot()->children[2]->keys);
    ASSERT_EQ(expected_q3, tree.GetRoot()->children[3]->keys);
    ASSERT_EQ(expected_q4, tree.GetRoot()->children[4]->keys);
    ASSERT_EQ(expected_q5, tree.GetRoot()->children[5]->keys);

    // insert L:
    //                         (p)
    //                /                   \
    //               /                     \
    //            (g   m)                (t   x)
    //          /    |    \             /   |   \
    //         /     |     \           /    |    \
    // (A B C D E) (j k l) (N O)   (Q R S) (U V) (Y Z)


    tree.Insert(tree.GetRoot(), 'L');
    auto expected_l = std::vector<char>{'P'};
    auto expected_l0 = std::vector<char>{'G', 'M'};
    auto expected_l00 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    auto expected_l01 = std::vector<char>{'J', 'K', 'L'};
    auto expected_l02 = std::vector<char>{'N', 'O'};
    auto expected_l1 = std::vector<char>{'T', 'X'};
    auto expected_l10 = std::vector<char>{'Q', 'R', 'S'};
    auto expected_l11 = std::vector<char>{'U', 'V'};
    auto expected_l12 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_l, tree.GetRoot()->keys);
    ASSERT_EQ(expected_l0, tree.GetRoot()->children[0]->keys);
    ASSERT_EQ(expected_l00, tree.GetRoot()->children[0]->children[0]->keys);
    ASSERT_EQ(expected_l01, tree.GetRoot()->children[0]->children[1]->keys);
    ASSERT_EQ(expected_l02, tree.GetRoot()->children[0]->children[2]->keys);
    ASSERT_EQ(expected_l1, tree.GetRoot()->children[1]->keys);
    ASSERT_EQ(expected_l10, tree.GetRoot()->children[1]->children[0]->keys);
    ASSERT_EQ(expected_l11, tree.GetRoot()->children[1]->children[1]->keys);
    ASSERT_EQ(expected_l12, tree.GetRoot()->children[1]->children[2]->keys);

    // insert F:
    //                            (P)
    //                  /                     \
    //                 /                       \
    //          (c    g    m)                 (T   X)
    //        /    /     \     \             /   |   \
    //       /    /       \     \           /    |    \
    // (a b c) (d e f) (J K L) (N O)   (Q R S) (U V) (Y Z)


    tree.Insert(tree.GetRoot(), 'F');
    auto expected_f = std::vector<char>{'P'};
    auto expected_f0 = std::vector<char>{'C', 'G', 'M'};
    auto expected_f00 = std::vector<char>{'A', 'B'};
    auto expected_f01 = std::vector<char>{'D', 'E', 'F'};
    auto expected_f02 = std::vector<char>{'J', 'K', 'L'};
    auto expected_f03 = std::vector<char>{'N', 'O'};
    auto expected_f1 = std::vector<char>{'T', 'X'};
    auto expected_f10 = std::vector<char>{'Q', 'R', 'S'};
    auto expected_f11 = std::vector<char>{'U', 'V'};
    auto expected_f12 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_l, tree.GetRoot()->keys);
    ASSERT_EQ(expected_f0, tree.GetRoot()->children[0]->keys);
    ASSERT_EQ(expected_f00, tree.GetRoot()->children[0]->children[0]->keys);
    ASSERT_EQ(expected_f01, tree.GetRoot()->children[0]->children[1]->keys);
    ASSERT_EQ(expected_f02, tree.GetRoot()->children[0]->children[2]->keys);
    ASSERT_EQ(expected_f03, tree.GetRoot()->children[0]->children[3]->keys);
    ASSERT_EQ(expected_f1, tree.GetRoot()->children[1]->keys);
    ASSERT_EQ(expected_f10, tree.GetRoot()->children[1]->children[0]->keys);
    ASSERT_EQ(expected_f11, tree.GetRoot()->children[1]->children[1]->keys);
    ASSERT_EQ(expected_f12, tree.GetRoot()->children[1]->children[2]->keys);
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

    auto root_node = new BTree::Node<char>();
    root_node->keys = {'G', 'M', 'P', 'X'};
    root_node->is_leaf = false;

    auto child_node1 = new BTree::Node<char>();
    child_node1->keys = {'A', 'C', 'D', 'E'};
    child_node1->is_leaf = true;

    auto child_node2 = new BTree::Node<char>();
    child_node2->keys = {'J', 'K'};
    child_node2->is_leaf = true;

    auto child_node3 = new BTree::Node<char>();
    child_node3->keys = {'N', 'O'};
    child_node3->is_leaf = true;

    auto child_node4 = new BTree::Node<char>();
    child_node4->keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->is_leaf = true;

    auto child_node5 = new BTree::Node<char>();
    child_node5->keys = {'Y', 'Z'};
    child_node5->is_leaf = true;

    root_node->children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = BTree::Tree<char>{};
    tree.SetRoot(root_node);
    tree.SetDegree(3);

    tree.Insert(tree.GetRoot(), 'B');
    tree.Insert(tree.GetRoot(), 'Q');
    tree.Insert(tree.GetRoot(), 'L');
    tree.Insert(tree.GetRoot(), 'F');

    // search B
    constexpr auto ch1 = 'B';
    auto [node1, key1] = tree.Search(tree.GetRoot(), ch1);
    const auto result_key1 = node1->keys[key1];
    ASSERT_EQ(ch1, result_key1);

    // search Q
    constexpr auto ch2 = 'Q';
    auto [node2, key2] = tree.Search(tree.GetRoot(), ch2);
    const auto result_key2 = node2->keys[key2];
    ASSERT_EQ(ch2, result_key2);

    // search L
    constexpr auto ch3 = 'L';
    auto [node3, key3] = tree.Search(tree.GetRoot(), ch3);
    const auto result_key3 = node3->keys[key3];
    ASSERT_EQ(ch3, result_key3);

    // search F
    constexpr auto ch4 = 'F';
    auto [node4, key4] = tree.Search(tree.GetRoot(), ch4);
    const auto result_key4 = node4->keys[key4];
    ASSERT_EQ(ch4, result_key4);
}
