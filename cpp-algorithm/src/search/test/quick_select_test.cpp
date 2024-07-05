#include "quick_select.h"

#include <gtest/gtest.h>

GTEST_TEST(FindKthSmallestElement, Successful1)
{
    auto array = std::vector{3, 2, 1, 5, 4};
    constexpr int k = 3;
    constexpr int expected = 3;
    const int result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, Successful2)
{
    auto array = std::vector{7, 4, 6, 3, 9, 1};
    constexpr int k = 4;
    constexpr int expected = 6;
    const int result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, ArrayWithDuplicateElements)
{
    auto array = std::vector{7, 7, 6, 6, 9, 9};
    constexpr int k = 4;
    constexpr int expected = 7;
    const int result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, OnlyOneElement)
{
    auto array = std::vector{7};
    constexpr int k = 1;
    constexpr int expected = 7;
    const int result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, ArrayWithNegativeElements)
{
    auto array = std::vector{-7, -4, -6, -3, -9, -1};
    constexpr int k = 4;
    constexpr int expected = -4;
    const int result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, KthLargestElement)
{
    auto array = std::vector{7, 4, 6, 3, 9, 1};
    constexpr int k = 2;
    constexpr int expected = 7;
    const int n = static_cast<int>(array.size());
    const int result = QuickSelect::FindKthSmallestElement(array, n - k + 1);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthLargestElement, Successful1)
{
    auto array = std::vector{7, 4, 6, 3, 9, 1};
    constexpr int k = 2;
    constexpr int expected = 7;
    const int result = QuickSelect::FindKthLargestElement(array, k);
    EXPECT_EQ(expected, result);
}
