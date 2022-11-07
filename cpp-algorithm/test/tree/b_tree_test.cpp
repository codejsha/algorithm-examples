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
    ASSERT_EQ(expectedB, tree.GetRoot()->Keys);
    ASSERT_EQ(expectedB0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expectedB1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expectedB2, tree.GetRoot()->Children[2]->Keys);
    ASSERT_EQ(expectedB3, tree.GetRoot()->Children[3]->Keys);
    ASSERT_EQ(expectedB4, tree.GetRoot()->Children[4]->Keys);

    // insert Q
    tree.Insert('Q');
    const auto expectedQ = std::vector<char>{'G', 'M', 'P', 'T', 'X'};
    const auto expectedQ0 = std::vector<char>{'A', 'B', 'C', 'D', 'E'};
    const auto expectedQ1 = std::vector<char>{'J', 'K'};
    const auto expectedQ2 = std::vector<char>{'N', 'O'};
    const auto expectedQ3 = std::vector<char>{'Q', 'R', 'S'};
    const auto expectedQ4 = std::vector<char>{'U', 'V'};
    const auto expectedQ5 = std::vector<char>{'Y', 'Z'};
    ASSERT_EQ(expectedQ, tree.GetRoot()->Keys);
    ASSERT_EQ(expectedQ0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expectedQ1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expectedQ2, tree.GetRoot()->Children[2]->Keys);
    ASSERT_EQ(expectedQ3, tree.GetRoot()->Children[3]->Keys);
    ASSERT_EQ(expectedQ4, tree.GetRoot()->Children[4]->Keys);
    ASSERT_EQ(expectedQ5, tree.GetRoot()->Children[5]->Keys);

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
    ASSERT_EQ(expectedL, tree.GetRoot()->Keys);
    ASSERT_EQ(expectedL0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expectedL00, tree.GetRoot()->Children[0]->Children[0]->Keys);
    ASSERT_EQ(expectedL01, tree.GetRoot()->Children[0]->Children[1]->Keys);
    ASSERT_EQ(expectedL02, tree.GetRoot()->Children[0]->Children[2]->Keys);
    ASSERT_EQ(expectedL1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expectedL10, tree.GetRoot()->Children[1]->Children[0]->Keys);
    ASSERT_EQ(expectedL11, tree.GetRoot()->Children[1]->Children[1]->Keys);
    ASSERT_EQ(expectedL12, tree.GetRoot()->Children[1]->Children[2]->Keys);

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
    ASSERT_EQ(expectedL, tree.GetRoot()->Keys);
    ASSERT_EQ(expectedF0, tree.GetRoot()->Children[0]->Keys);
    ASSERT_EQ(expectedF00, tree.GetRoot()->Children[0]->Children[0]->Keys);
    ASSERT_EQ(expectedF01, tree.GetRoot()->Children[0]->Children[1]->Keys);
    ASSERT_EQ(expectedF02, tree.GetRoot()->Children[0]->Children[2]->Keys);
    ASSERT_EQ(expectedF03, tree.GetRoot()->Children[0]->Children[3]->Keys);
    ASSERT_EQ(expectedF1, tree.GetRoot()->Children[1]->Keys);
    ASSERT_EQ(expectedF10, tree.GetRoot()->Children[1]->Children[0]->Keys);
    ASSERT_EQ(expectedF11, tree.GetRoot()->Children[1]->Children[1]->Keys);
    ASSERT_EQ(expectedF12, tree.GetRoot()->Children[1]->Children[2]->Keys);
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
    ASSERT_EQ(ch1, resultKey1);

    // search Q
    constexpr auto ch2 = 'Q';
    const auto [node2, key2] = tree.Search(ch2);
    const auto resultKey2 = node2->Keys[key2];
    ASSERT_EQ(ch2, resultKey2);

    // search L
    constexpr auto ch3 = 'L';
    const auto [node3, key3] = tree.Search(ch3);
    const auto resultKey3 = node3->Keys[key3];
    ASSERT_EQ(ch3, resultKey3);

    // search F
    constexpr auto ch4 = 'F';
    const auto [node4, key4] = tree.Search(ch4);
    const auto resultKey4 = node4->Keys[key4];
    ASSERT_EQ(ch4, resultKey4);
}
