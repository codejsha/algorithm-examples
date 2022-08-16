#include "binary_search_tree.h"
#include "tree.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <ranges>

TEST(BinarySearchTreeTest, PreorderTreeWalk)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expectedSeq = std::vector<int>{15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.PreorderTreeWalk();
    ASSERT_EQ(static_cast<int>(result.size()), static_cast<int>(expectedSeq.size()))
        << "Vectors input and result are of unequal length";

    const auto isEqual = std::ranges::equal(result, expectedSeq);
    ASSERT_EQ(isEqual, true) << "Vectors input and result differ" << std::endl;
}

TEST(BinarySearchTreeTest, InorderTreeWalk)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expectedSeq = std::vector<int>{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.InorderTreeWalk();
    ASSERT_EQ(static_cast<int>(result.size()), static_cast<int>(expectedSeq.size()))
        << "Vectors input and result are of unequal length";

    const auto isEqual = std::ranges::equal(result, expectedSeq);
    ASSERT_EQ(isEqual, true) << "Vectors input and result differ" << std::endl;
}

TEST(BinarySearchTreeTest, PostorderTreeWalk)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expectedSeq = std::vector<int>{2, 4, 3, 9, 13, 7, 6, 17, 20, 18, 15};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.PostorderTreeWalk();
    ASSERT_EQ(static_cast<int>(result.size()), static_cast<int>(expectedSeq.size()))
        << "Vectors input and result are of unequal length";

    const auto isEqual = std::ranges::equal(result, expectedSeq);
    ASSERT_EQ(isEqual, true) << "Vectors input and result differ" << std::endl;
}

TEST(BinarySearchTreeTest, GetMinimum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expectedValue = *std::ranges::min_element(seq);

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreeMinimum();
    ASSERT_EQ(result->Key, expectedValue);
}

TEST(BinarySearchTreeTest, GetMaximum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expectedValue = *std::ranges::max_element(seq);

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreeMaximum();
    ASSERT_EQ(result->Key, expectedValue);
}

TEST(BinarySearchTreeTest, GetPredecessor)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expectedValue = 13;

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreePredecessor(15);
    ASSERT_EQ(result->Key, expectedValue);
}

TEST(BinarySearchTreeTest, GetSuccessor)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expectedValue = 17;

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreeSuccessor(15);
    ASSERT_EQ(result->Key, expectedValue);
}

TEST(BinarySearchTreeTest, RecursiveTreeSearch)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.RecursiveTreeSearch(seq.back());
    ASSERT_EQ(result->Key, seq.back());
}

TEST(BinarySearchTreeTest, IterativeTreeSearch)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.IterativeTreeSearch(seq.back());
    ASSERT_EQ(result->Key, seq.back());
}

TEST(BinarySearchTreeTest, Delete)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    auto seqSize = static_cast<int>(seq.size());

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    for (auto& element : seq)
    {
        tree.Delete(element);
        const auto result = tree.InorderTreeWalk();
        ASSERT_EQ(static_cast<int>(result.size()), --seqSize)
            << "Vectors input and result are of unequal length";
    }
}
