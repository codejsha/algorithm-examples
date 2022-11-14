#include "permutation.h"

#include <gtest/gtest.h>

GTEST_TEST(PermutationTest, Permutation)
{
    const auto str = "abc";

    Permutation::Permutation(str, "");
    // result:
    // abc
    // acb
    // bac
    // bca
    // cab
    // cba
}

GTEST_TEST(PermutationTest, ApplyPermutationWithAdditionalSpace)
{
    const auto arr = std::vector<char>{'a', 'b', 'c', 'd'};
    const auto permutation = std::vector<int>{2, 0, 1, 3};
    const auto expected = std::vector<char>{'b', 'c', 'a', 'd'};
    const auto result = Permutation::ApplyPermutationWithAdditionalSpace(permutation, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(PermutationTest, ApplyPermutationBySwap)
{
    auto arr = std::vector<char>{'a', 'b', 'c', 'd'};
    auto permutation = std::vector<int>{2, 0, 1, 3};
    const auto expected = std::vector<char>{'b', 'c', 'a', 'd'};
    const auto result = Permutation::ApplyPermutationBySwap(permutation, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(PermutationTest, InversePermutation)
{
    const auto arr = std::vector<char>{'a', 'b', 'c', 'd', 'e'};
    const auto permutation = std::vector<int>{1, 0, 3, 4, 2};
    const auto expected = std::vector<int>{1, 0, 4, 2, 3};
    const auto result = Permutation::InversePermutation(permutation, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(PermutationTest, NextPermutation)
{
    auto permutation = std::vector<int>{6, 2, 1, 5, 4, 3, 0};
    const auto expected = std::vector<int>{6, 2, 3, 0, 1, 4, 5};
    const auto result = Permutation::NextPermutation(permutation);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(PermutationTest, PreviousPermutation)
{
    auto permutation = std::vector<int>{4, 3, 2, 1};
    const auto expected = std::vector<int>{4, 3, 1, 2};
    const auto result = Permutation::PreviousPermutation(permutation);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(PermutationTest, KthPermutation)
{
    auto permutation = std::vector<int>{1, 2, 3};
    constexpr auto kth = 4;
    const auto expected = std::vector<int>{2, 3, 1};
    const auto result = Permutation::KthPermutation(permutation, kth);
    EXPECT_EQ(expected, result);
}