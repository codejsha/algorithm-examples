#include "b_tree.h"

#include <gtest/gtest.h>

TEST(BTreeTest, SimpleInsert)
{
    const auto rootNode = new Tree::BTreeNode();
    rootNode->Keys = {'G', 'M', 'P', 'X'};
    rootNode->IsLeaf = false;

    const auto childNode1 = new Tree::BTreeNode();
    childNode1->Keys = {'A', 'C', 'D', 'E'};
    childNode1->IsLeaf = true;

    const auto childNode2 = new Tree::BTreeNode();
    childNode2->Keys = {'J', 'K'};
    childNode2->IsLeaf = true;

    const auto childNode3 = new Tree::BTreeNode();
    childNode3->Keys = {'N', 'O'};
    childNode3->IsLeaf = true;

    const auto childNode4 = new Tree::BTreeNode();
    childNode4->Keys = {'R', 'S', 'T', 'U', 'V'};
    childNode4->IsLeaf = true;

    const auto childNode5 = new Tree::BTreeNode();
    childNode5->Keys = {'Y', 'Z'};
    childNode5->IsLeaf = true;

    rootNode->Children = {childNode1, childNode2, childNode3, childNode4, childNode5};
    auto tree = Tree::BTree{};
    tree.SetRoot(rootNode);
    tree.SetDegree(3);

    // insert B
    tree.Insert('B');
    const auto expectedB = std::vector<char>{'G', 'M', 'P', 'X'};
    const auto expectedB0 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    const auto expectedB1 = std::vector<char>{'J', 'K'};
    const auto expectedB2 = std::vector<char>{'N', 'O'};
    const auto expectedB3 = std::vector<char>{'R', 'S', 'T', 'U', 'V'};
    const auto expectedB4 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(tree.GetRoot()->Keys, expectedB);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Keys, expectedB0);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Keys, expectedB1);
    ASSERT_EQ(tree.GetRoot()->Children[2]->Keys, expectedB2);
    ASSERT_EQ(tree.GetRoot()->Children[3]->Keys, expectedB3);
    ASSERT_EQ(tree.GetRoot()->Children[4]->Keys, expectedB4);

    // insert Q
    tree.Insert('Q');
    const auto expectedQ = std::vector<char>{'G', 'M', 'P', 'T', 'X'};
    const auto expectedQ0 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    const auto expectedQ1 = std::vector<char>{'J', 'K'};
    const auto expectedQ2 = std::vector<char>{'N', 'O'};
    const auto expectedQ3 = std::vector<char>{'Q', 'R', 'S'};
    const auto expectedQ4 = std::vector<char>{'U', 'V'};
    const auto expectedQ5 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(tree.GetRoot()->Keys, expectedQ);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Keys, expectedQ0);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Keys, expectedQ1);
    ASSERT_EQ(tree.GetRoot()->Children[2]->Keys, expectedQ2);
    ASSERT_EQ(tree.GetRoot()->Children[3]->Keys, expectedQ3);
    ASSERT_EQ(tree.GetRoot()->Children[4]->Keys, expectedQ4);
    ASSERT_EQ(tree.GetRoot()->Children[5]->Keys, expectedQ5);

    // insert L
    tree.Insert('L');
    const auto expectedL = std::vector<char>{'P'};
    const auto expectedL0 = std::vector<char>{'G', 'M'};
    const auto expectedL00 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    const auto expectedL01 = std::vector<char>{'J', 'K', 'L'};
    const auto expectedL02 = std::vector<char>{'N', 'O'};
    const auto expectedL1 = std::vector<char>{'T', 'X'};
    const auto expectedL10 = std::vector<char>{'Q', 'R', 'S'};
    const auto expectedL11 = std::vector<char>{'U', 'V'};
    const auto expectedL12 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(tree.GetRoot()->Keys, expectedL);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Keys, expectedL0);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Children[0]->Keys, expectedL00);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Children[1]->Keys, expectedL01);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Children[2]->Keys, expectedL02);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Keys, expectedL1);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Children[0]->Keys, expectedL10);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Children[1]->Keys, expectedL11);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Children[2]->Keys, expectedL12);

    // insert F
    tree.Insert('F');
    const auto expectedF = std::vector<char>{'P'};
    const auto expectedF0 = std::vector<char>{'C', 'G', 'M'};
    const auto expectedF00 = std::vector<char>{'A', 'B'};
    const auto expectedF01 = std::vector<char>{'D', 'E', 'F'};
    const auto expectedF02 = std::vector<char>{'J', 'K', 'L'};
    const auto expectedF03 = std::vector<char>{'N', 'O'};
    const auto expectedF1 = std::vector<char>{'T', 'X'};
    const auto expectedF10 = std::vector<char>{'Q', 'R', 'S'};
    const auto expectedF11 = std::vector<char>{'U', 'V'};
    const auto expectedF12 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(tree.GetRoot()->Keys, expectedL);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Keys, expectedF0);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Children[0]->Keys, expectedF00);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Children[1]->Keys, expectedF01);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Children[2]->Keys, expectedF02);
    ASSERT_EQ(tree.GetRoot()->Children[0]->Children[3]->Keys, expectedF03);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Keys, expectedF1);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Children[0]->Keys, expectedF10);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Children[1]->Keys, expectedF11);
    ASSERT_EQ(tree.GetRoot()->Children[1]->Children[2]->Keys, expectedF12);
}

TEST(BTreeTest, SimpleSearch)
{
    const auto rootNode = new Tree::BTreeNode();
    rootNode->Keys = {'G', 'M', 'P', 'X'};
    rootNode->IsLeaf = false;

    const auto childNode1 = new Tree::BTreeNode();
    childNode1->Keys = {'A', 'C', 'D', 'E'};
    childNode1->IsLeaf = true;

    const auto childNode2 = new Tree::BTreeNode();
    childNode2->Keys = {'J', 'K'};
    childNode2->IsLeaf = true;

    const auto childNode3 = new Tree::BTreeNode();
    childNode3->Keys = {'N', 'O'};
    childNode3->IsLeaf = true;

    const auto childNode4 = new Tree::BTreeNode();
    childNode4->Keys = {'R', 'S', 'T', 'U', 'V'};
    childNode4->IsLeaf = true;

    const auto childNode5 = new Tree::BTreeNode();
    childNode5->Keys = {'Y', 'Z'};
    childNode5->IsLeaf = true;

    rootNode->Children = {childNode1, childNode2, childNode3, childNode4, childNode5};
    auto tree = Tree::BTree{};
    tree.SetRoot(rootNode);
    tree.SetDegree(3);

    tree.Insert('B');
    tree.Insert('Q');
    tree.Insert('L');
    tree.Insert('F');

    // search B
    constexpr auto ch1 = 'B';
    const auto [node1, key1] = tree.Search(ch1);
    const auto resultKey1 = node1->Keys[key1];
    ASSERT_EQ(resultKey1, ch1);

    // search Q
    constexpr auto ch2 = 'Q';
    const auto [node2, key2] = tree.Search(ch2);
    const auto resultKey2 = node2->Keys[key2];
    ASSERT_EQ(resultKey2, ch2);

    // search L
    constexpr auto ch3 = 'L';
    const auto [node3, key3] = tree.Search(ch3);
    const auto resultKey3 = node3->Keys[key3];
    ASSERT_EQ(resultKey3, ch3);

    // search F
    constexpr auto ch4 = 'F';
    const auto [node4, key4] = tree.Search(ch4);
    const auto resultKey4 = node4->Keys[key4];
    ASSERT_EQ(resultKey4, ch4);
}
