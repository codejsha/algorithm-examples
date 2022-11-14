#include "binary_search_tree.h"
#include "tree.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <ranges>

GTEST_TEST(BinarySearchTreeTest, PreorderTreeWalk)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = std::vector<int>{15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.PreorderTreeWalk();
    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    ASSERT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(BinarySearchTreeTest, InorderTreeWalk)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = std::vector<int>{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.InorderTreeWalk();
    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    ASSERT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(BinarySearchTreeTest, PostorderTreeWalk)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = std::vector<int>{2, 4, 3, 9, 13, 7, 6, 17, 20, 18, 15};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.PostorderTreeWalk();
    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    ASSERT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(BinarySearchTreeTest, GetMinimum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = *std::ranges::min_element(seq);

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreeMinimum();
    ASSERT_EQ(expected, result->Key);
}

GTEST_TEST(BinarySearchTreeTest, GetMaximum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = *std::ranges::max_element(seq);

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreeMaximum();
    ASSERT_EQ(expected, result->Key);
}

GTEST_TEST(BinarySearchTreeTest, GetPredecessor)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expected = 13;

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreePredecessor(15);
    ASSERT_EQ(expected, result->Key);
}

GTEST_TEST(BinarySearchTreeTest, GetSuccessor)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expected = 17;

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.TreeSuccessor(15);
    ASSERT_EQ(expected, result->Key);
}

GTEST_TEST(BinarySearchTreeTest, RecursiveTreeSearch)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.RecursiveTreeSearch(seq.back());
    ASSERT_EQ(seq.back(), result->Key);
}

GTEST_TEST(BinarySearchTreeTest, IterativeTreeSearch)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.IterativeTreeSearch(seq.back());
    ASSERT_EQ(seq.back(), result->Key);
}

GTEST_TEST(BinarySearchTreeTest, Delete)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    auto seq_size = static_cast<int>(seq.size());

    auto tree = Tree::BinarySearchTree{};
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    for (auto& element : seq)
    {
        tree.Delete(element);
        const auto result = tree.InorderTreeWalk();
        ASSERT_EQ(--seq_size, static_cast<int>(result.size()))
            << "Vectors input and result are of unequal length";
    }
}
