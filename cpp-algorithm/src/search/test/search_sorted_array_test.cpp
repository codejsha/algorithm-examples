#include "search_sorted_array.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(SearchSortedArray, SearchFirstOfKey)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr int key = 108;
    constexpr int expected = 3;
    const int result = SearchSortedArray::SearchFirstOfKey(array, key);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SearchSortedArray, SearchFirstGreaterThanKeyCase1)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr int key = 108;
    constexpr int expected = 5;
    const int result = SearchSortedArray::SearchFirstGreaterThanKey(array, key);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SearchSortedArray, SearchFirstGreaterThanKeyCase2)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr int key = 285;
    constexpr int expected = 9;
    const int result = SearchSortedArray::SearchFirstGreaterThanKey(array, key);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SearchSortedArray, SearchFirstGreaterThanKeyCase3)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr int key = -13;
    constexpr int expected = 1;
    const int result = SearchSortedArray::SearchFirstGreaterThanKey(array, key);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SearchSortedArray, SearchEntryEqualToItsIndex)
{
    const auto array = std::vector{-2, 0, 2, 3, 6, 7, 9};
    const auto expected = std::vector{2, 3};
    const auto result = SearchSortedArray::SearchEntryEqualToItsIndex(array);
    const auto is_entry = std::ranges::find_if(array, [](auto x) { return (x == 2) || (x == 3); });
    EXPECT_TRUE(*is_entry);
}

GTEST_TEST(SearchSortedArray, SearchSmallestElementInCyclicallySortedArray)
{
    const auto array = std::vector{378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
    constexpr int expected = 4;
    const int result = SearchSortedArray::SearchSmallestElementInCyclicallySortedArray(array);
    EXPECT_EQ(expected, result);
}
