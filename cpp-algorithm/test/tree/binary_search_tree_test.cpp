#include "binary_search_tree.h"
#include <gtest/gtest.h>

TEST(BinarySearchTreeTest, InorderTreeWalk)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected_seq = std::vector<int>{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.InorderTreeWalk();

    ASSERT_EQ(static_cast<int>(result.size()), static_cast<int>(expected_seq.size())) << "Vectors x and y are of unequal length";

    for (int i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(result[i], expected_seq[i]) << "Vectors x and y differ at index " << i;
    }
}

TEST(BinarySearchTreeTest, RecursiveTreeSearch)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.RecursiveTreeSearch(seq.back());

    ASSERT_EQ(result->value, seq.back());
}

TEST(BinarySearchTreeTest, IterativeTreeSearch)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.IterativeTreeSearch(seq.back());

    ASSERT_EQ(result->value, seq.back());
}

TEST(BinarySearchTreeTest, GetMinimum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected_value = *std::ranges::min_element(seq);

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.GetMinimum();

    ASSERT_EQ(result->value, expected_value);
}

TEST(BinarySearchTreeTest, GetMaximum)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected_value = *std::ranges::max_element(seq);

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.GetMaximum();

    ASSERT_EQ(result->value, expected_value);
}

TEST(BinarySearchTreeTest, GetSuccessor)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expected_value = 17;

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.GetSuccessor(15);

    ASSERT_EQ(result->value, expected_value);
}

TEST(BinarySearchTreeTest, GetPredecessor)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expected_value = 13;

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    const auto result = tree.GetPredecessor(15);

    ASSERT_EQ(result->value, expected_value);
}

TEST(BinarySearchTreeTest, Delete)
{
    const auto seq = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    auto seq_size = static_cast<int>(seq.size());

    auto tree = tree::BinarySearchTree();
    for (const auto& element : seq)
    {
        tree.Insert(element);
    }

    for (auto& element : seq)
    {
        tree.Delete(element);
        const auto result = tree.InorderTreeWalk();
        ASSERT_EQ(static_cast<int>(result.size()), --seq_size) << "Vectors x and y are of unequal length";
    }
}
