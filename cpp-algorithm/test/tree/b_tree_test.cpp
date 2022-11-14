#include "b_tree.h"

#include <gtest/gtest.h>

GTEST_TEST(BTreeTest, SimpleInsert)
{
    const auto root_node = new Tree::BTreeNode();
    root_node->Keys = {'G', 'M', 'P', 'X'};
    root_node->IsLeaf = false;

    const auto child_node1 = new Tree::BTreeNode();
    child_node1->Keys = {'A', 'C', 'D', 'E'};
    child_node1->IsLeaf = true;

    const auto child_node2 = new Tree::BTreeNode();
    child_node2->Keys = {'J', 'K'};
    child_node2->IsLeaf = true;

    const auto child_node3 = new Tree::BTreeNode();
    child_node3->Keys = {'N', 'O'};
    child_node3->IsLeaf = true;

    const auto child_node4 = new Tree::BTreeNode();
    child_node4->Keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->IsLeaf = true;

    const auto child_node5 = new Tree::BTreeNode();
    child_node5->Keys = {'Y', 'Z'};
    child_node5->IsLeaf = true;

    root_node->Children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = Tree::BTree{};
    tree.SetRoot(root_node);
    tree.SetDegree(3);

    // insert B
    tree.Insert('B');
    const auto expected_b = std::vector<char>{'G', 'M', 'P', 'X'};
    const auto expected_b0 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    const auto expected_b1 = std::vector<char>{'J', 'K'};
    const auto expected_b2 = std::vector<char>{'N', 'O'};
    const auto expected_b3 = std::vector<char>{'R', 'S', 'T', 'U', 'V'};
    const auto expected_b4 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_b, tree.GetRoot()->Keys);
    ASSERT_EQ(expected_b0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expected_b1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expected_b2, tree.GetRoot()->Children[2]->Keys);
    ASSERT_EQ(expected_b3, tree.GetRoot()->Children[3]->Keys);
    ASSERT_EQ(expected_b4, tree.GetRoot()->Children[4]->Keys);

    // insert Q
    tree.Insert('Q');
    const auto expected_q = std::vector<char>{'G', 'M', 'P', 'T', 'X'};
    const auto expected_q0 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    const auto expected_q1 = std::vector<char>{'J', 'K'};
    const auto expected_q2 = std::vector<char>{'N', 'O'};
    const auto expected_q3 = std::vector<char>{'Q', 'R', 'S'};
    const auto expected_q4 = std::vector<char>{'U', 'V'};
    const auto expected_q5 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_q, tree.GetRoot()->Keys);
    ASSERT_EQ(expected_q0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expected_q1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expected_q2, tree.GetRoot()->Children[2]->Keys);
    ASSERT_EQ(expected_q3, tree.GetRoot()->Children[3]->Keys);
    ASSERT_EQ(expected_q4, tree.GetRoot()->Children[4]->Keys);
    ASSERT_EQ(expected_q5, tree.GetRoot()->Children[5]->Keys);

    // insert L
    tree.Insert('L');
    const auto expected_l = std::vector<char>{'P'};
    const auto expected_l0 = std::vector<char>{'G', 'M'};
    const auto expected_l00 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    const auto expected_l01 = std::vector<char>{'J', 'K', 'L'};
    const auto expected_l02 = std::vector<char>{'N', 'O'};
    const auto expected_l1 = std::vector<char>{'T', 'X'};
    const auto expected_l10 = std::vector<char>{'Q', 'R', 'S'};
    const auto expected_l11 = std::vector<char>{'U', 'V'};
    const auto expected_l12 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_l, tree.GetRoot()->Keys);
    ASSERT_EQ(expected_l0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expected_l00, tree.GetRoot()->Children[0]->Children[0]->Keys);
    ASSERT_EQ(expected_l01, tree.GetRoot()->Children[0]->Children[1]->Keys);
    ASSERT_EQ(expected_l02, tree.GetRoot()->Children[0]->Children[2]->Keys);
    ASSERT_EQ(expected_l1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expected_l10, tree.GetRoot()->Children[1]->Children[0]->Keys);
    ASSERT_EQ(expected_l11, tree.GetRoot()->Children[1]->Children[1]->Keys);
    ASSERT_EQ(expected_l12, tree.GetRoot()->Children[1]->Children[2]->Keys);

    // insert F
    tree.Insert('F');
    const auto expected_f = std::vector<char>{'P'};
    const auto expected_f0 = std::vector<char>{'C', 'G', 'M'};
    const auto expected_f00 = std::vector<char>{'A', 'B'};
    const auto expected_f01 = std::vector<char>{'D', 'E', 'F'};
    const auto expected_f02 = std::vector<char>{'J', 'K', 'L'};
    const auto expected_f03 = std::vector<char>{'N', 'O'};
    const auto expected_f1 = std::vector<char>{'T', 'X'};
    const auto expected_f10 = std::vector<char>{'Q', 'R', 'S'};
    const auto expected_f11 = std::vector<char>{'U', 'V'};
    const auto expected_f12 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expected_l, tree.GetRoot()->Keys);
    ASSERT_EQ(expected_f0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expected_f00, tree.GetRoot()->Children[0]->Children[0]->Keys);
    ASSERT_EQ(expected_f01, tree.GetRoot()->Children[0]->Children[1]->Keys);
    ASSERT_EQ(expected_f02, tree.GetRoot()->Children[0]->Children[2]->Keys);
    ASSERT_EQ(expected_f03, tree.GetRoot()->Children[0]->Children[3]->Keys);
    ASSERT_EQ(expected_f1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expected_f10, tree.GetRoot()->Children[1]->Children[0]->Keys);
    ASSERT_EQ(expected_f11, tree.GetRoot()->Children[1]->Children[1]->Keys);
    ASSERT_EQ(expected_f12, tree.GetRoot()->Children[1]->Children[2]->Keys);
}

GTEST_TEST(BTreeTest, SimpleSearch)
{
    const auto root_node = new Tree::BTreeNode();
    root_node->Keys = {'G', 'M', 'P', 'X'};
    root_node->IsLeaf = false;

    const auto child_node1 = new Tree::BTreeNode();
    child_node1->Keys = {'A', 'C', 'D', 'E'};
    child_node1->IsLeaf = true;

    const auto child_node2 = new Tree::BTreeNode();
    child_node2->Keys = {'J', 'K'};
    child_node2->IsLeaf = true;

    const auto child_node3 = new Tree::BTreeNode();
    child_node3->Keys = {'N', 'O'};
    child_node3->IsLeaf = true;

    const auto child_node4 = new Tree::BTreeNode();
    child_node4->Keys = {'R', 'S', 'T', 'U', 'V'};
    child_node4->IsLeaf = true;

    const auto child_node5 = new Tree::BTreeNode();
    child_node5->Keys = {'Y', 'Z'};
    child_node5->IsLeaf = true;

    root_node->Children = {child_node1, child_node2, child_node3, child_node4, child_node5};
    auto tree = Tree::BTree{};
    tree.SetRoot(root_node);
    tree.SetDegree(3);

    tree.Insert('B');
    tree.Insert('Q');
    tree.Insert('L');
    tree.Insert('F');

    // search B
    constexpr auto ch1 = 'B';
    const auto [node1, key1] = tree.Search(ch1);
    const auto result_key1 = node1->Keys[key1];
    ASSERT_EQ(ch1, result_key1);

    // search Q
    constexpr auto ch2 = 'Q';
    const auto [node2, key2] = tree.Search(ch2);
    const auto result_key2 = node2->Keys[key2];
    ASSERT_EQ(ch2, result_key2);

    // search L
    constexpr auto ch3 = 'L';
    const auto [node3, key3] = tree.Search(ch3);
    const auto result_key3 = node3->Keys[key3];
    ASSERT_EQ(ch3, result_key3);

    // search F
    constexpr auto ch4 = 'F';
    const auto [node4, key4] = tree.Search(ch4);
    const auto result_key4 = node4->Keys[key4];
    ASSERT_EQ(ch4, result_key4);
}
