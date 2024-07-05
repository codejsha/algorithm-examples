#include "permutation.h"

#include <gtest/gtest.h>

GTEST_TEST(Permutation, Permutation)
{
    const std::string str = "abc";

    Permutation::Permutation(str, "");
    // result:
    // abc
    // acb
    // bac
    // bca
    // cab
    // cba
}

GTEST_TEST(Permutation, ApplyPermutationWithAdditionalSpace)
{
    const auto arr = std::vector<char>{'a', 'b', 'c', 'd'};
    const auto permutation = std::vector<int>{2, 0, 1, 3};
    const auto expected = std::vector<char>{'b', 'c', 'a', 'd'};
    const auto result = Permutation::ApplyPermutationWithAdditionalSpace(permutation, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(Permutation, ApplyPermutationBySwap)
{
    auto arr = std::vector<char>{'a', 'b', 'c', 'd'};
    auto permutation = std::vector<int>{2, 0, 1, 3};
    const auto expected = std::vector<char>{'b', 'c', 'a', 'd'};
    const auto result = Permutation::ApplyPermutationBySwap(permutation, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(Permutation, InversePermutation)
{
    const auto arr = std::vector<char>{'a', 'b', 'c', 'd', 'e'};
    const auto permutation = std::vector<int>{1, 0, 3, 4, 2};
    const auto expected = std::vector<int>{1, 0, 4, 2, 3};
    const auto result = Permutation::InversePermutation(permutation, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(Permutation, NextPermutation)
{
    auto permutation = std::vector<int>{6, 2, 1, 5, 4, 3, 0};
    const auto expected = std::vector<int>{6, 2, 3, 0, 1, 4, 5};
    const auto result = Permutation::NextPermutation(permutation);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(Permutation, PreviousPermutation)
{
    auto permutation = std::vector<int>{4, 3, 2, 1};
    const auto expected = std::vector<int>{4, 3, 1, 2};
    const auto result = Permutation::PreviousPermutation(permutation);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(Permutation, KthPermutation)
{
    auto permutation = std::vector<int>{1, 2, 3};
    constexpr int kth = 4;
    const auto expected = std::vector<int>{2, 3, 1};
    const auto result = Permutation::KthPermutation(permutation, kth);
    EXPECT_EQ(expected, result);
}
