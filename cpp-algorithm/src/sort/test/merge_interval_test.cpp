#include "merge_interval.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(MergeIntervals, ValidNewIntervalInput)
{
    auto intervals = std::vector<std::vector<int>>{{-4, -1}, {0, 2}, {3, 6}, {7, 9}, {11, 12}, {14, 17}};
    const auto new_interval = std::vector<int>{1, 8};
    const auto expected = std::vector<std::vector<int>>{{-4, -1}, {0, 9}, {11, 12}, {14, 17}};
    const auto result = MergeInterval::MergeIntervals(intervals, new_interval);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(MergeIntervals, ValidIntervals1)
{
    auto intervals = std::vector<std::vector<int>>{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    const auto expected = std::vector<std::vector<int>>{{1, 6}, {8, 10}, {15, 18}};
    const auto result = MergeInterval::MergeIntervals(intervals);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(MergeIntervals, ValidIntervals2)
{
    auto intervals = std::vector<std::vector<int>>{{1, 4}, {4, 5}};
    const auto expected = std::vector<std::vector<int>>{{1, 5}};
    const auto result = MergeInterval::MergeIntervals(intervals);
    EXPECT_EQ(expected, result);
}
