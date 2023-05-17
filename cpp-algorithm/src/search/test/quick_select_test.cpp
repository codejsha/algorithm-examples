#include "quick_select.h"

#include <gtest/gtest.h>

GTEST_TEST(FindKthSmallestElement, KthSmallestElementCase1)
{
    auto array = std::vector{3, 2, 1, 5, 4};
    constexpr auto k = 3;
    constexpr auto expected = 3;
    const auto result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, KthSmallestElementCase2)
{
    auto array = std::vector{7, 4, 6, 3, 9, 1};
    constexpr auto k = 4;
    constexpr auto expected = 6;
    const auto result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, KthLargestElement)
{
    auto array = std::vector{7, 4, 6, 3, 9, 1};
    constexpr auto k = 2;
    constexpr auto expected = 7;
    const auto n = static_cast<int>(array.size());
    const auto result = QuickSelect::FindKthSmallestElement(array, n - k + 1);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, ArrayWithDuplicateElements)
{
    auto array = std::vector{7, 7, 6, 6, 9, 9};
    constexpr auto k = 4;
    constexpr auto expected = 7;
    const auto result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, OnlyOneElement)
{
    auto array = std::vector{7};
    constexpr auto k = 1;
    constexpr auto expected = 7;
    const auto result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FindKthSmallestElement, ArrayWithNegativeElements)
{
    auto array = std::vector{-7, -4, -6, -3, -9, -1};
    constexpr auto k = 4;
    constexpr auto expected = -4;
    const auto result = QuickSelect::FindKthSmallestElement(array, k);
    EXPECT_EQ(expected, result);
}
