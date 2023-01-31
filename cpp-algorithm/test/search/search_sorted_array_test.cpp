#include "search_sorted_array.h"

#include <gtest/gtest.h>

GTEST_TEST(SearchSortedArray, SearchFirstOfKey)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr auto key = 108;
    constexpr auto expected = 3;
    const auto result = SearchSortedArray::SearchFirstOfKey(array, key);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SearchSortedArray, SearchFirstGreaterThanKeyCase1)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr auto key = 108;
    constexpr auto expected = 5;
    const auto result = SearchSortedArray::SearchFirstGreaterThanKey(array, key);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SearchSortedArray, SearchFirstGreaterThanKeyCase2)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr auto key = 285;
    constexpr auto expected = 9;
    const auto result = SearchSortedArray::SearchFirstGreaterThanKey(array, key);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SearchSortedArray, SearchFirstGreaterThanKeyCase3)
{
    const auto array = std::vector{-14, 10, 2, 108, 108, 243, 285, 285, 285, 401};
    constexpr auto key = -13;
    constexpr auto expected = 1;
    const auto result = SearchSortedArray::SearchFirstGreaterThanKey(array, key);
    EXPECT_EQ(expected, result);
}
