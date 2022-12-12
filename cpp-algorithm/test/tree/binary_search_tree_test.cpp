#include "binary_search_tree.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(BinarySearchTreeTest, PreorderTraversal)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = std::vector<int>{15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    auto result = std::vector<int>{};
    tree.PreorderTraversal(tree.GetRoot(), result);
    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(BinarySearchTreeTest, InorderTraversal)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = std::vector<int>{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    auto result = std::vector<int>{};
    tree.InorderTraversal(tree.GetRoot(), result);
    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(BinarySearchTreeTest, PostorderTraversal)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = std::vector<int>{2, 4, 3, 9, 13, 7, 6, 17, 20, 18, 15};

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    auto result = std::vector<int>{};
    tree.PostorderTraversal(tree.GetRoot(), result);
    ASSERT_EQ(static_cast<int>(expected.size()), static_cast<int>(result.size()))
        << "Vectors input and result are of unequal length";

    const auto is_equal = std::ranges::equal(expected, result);
    EXPECT_EQ(true, is_equal) << "Vectors input and result differ" << std::endl;
}

GTEST_TEST(BinarySearchTreeTest, Minimum)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = *std::ranges::min_element(keys);

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    const auto result = tree.Minimum(tree.GetRoot());
    EXPECT_EQ(expected, result->key);
}

GTEST_TEST(BinarySearchTreeTest, Maximum)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = *std::ranges::max_element(keys);

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    const auto result = tree.Maximum(tree.GetRoot());
    EXPECT_EQ(expected, result->key);
}

GTEST_TEST(BinarySearchTreeTest, Predecessor)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expected = 13;

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    const auto result = tree.Predecessor(15)->key;
    EXPECT_EQ(expected, result);
}

GTEST_TEST(BinarySearchTreeTest, Successor)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    constexpr auto expected = 17;

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    const auto result = tree.Successor(15)->key;
    EXPECT_EQ(expected, result);
}

GTEST_TEST(BinarySearchTreeTest, IterativeSearch)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = keys.back();

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    const auto result = tree.IterativeSearch(tree.GetRoot(), keys.back())->key;
    EXPECT_EQ(expected, result);
}

GTEST_TEST(BinarySearchTreeTest, RecursiveSearch)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    const auto expected = keys.back();

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    const auto result = tree.RecursiveSearch(tree.GetRoot(), keys.back())->key;
    EXPECT_EQ(expected, result);
}

GTEST_TEST(BinarySearchTreeTest, Delete_1)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    auto seq_size = static_cast<int>(keys.size());

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto key : keys)
    {
        tree.Delete(tree.GetRoot(), key);
        auto result = std::vector<int>{};
        tree.InorderTraversal(tree.GetRoot(), result);
    }
}

GTEST_TEST(BinarySearchTreeTest, Delete_2)
{
    auto tree = BinarySearchTree::Tree<int>{};
    const auto keys = std::vector<int>{8, 3, 10, 1, 6, 14, 4, 7, 13};
    auto seq_size = static_cast<int>(keys.size());

    for (const auto key : keys)
    {
        tree.Insert(key);
    }

    for (auto key : keys)
    {
        tree.Delete(tree.GetRoot(), key);
        auto result = std::vector<int>{};
        tree.InorderTraversal(tree.GetRoot(), result);
    }
}
