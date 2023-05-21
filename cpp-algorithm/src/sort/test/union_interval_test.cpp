#include "union_interval.h"

#include <gtest/gtest.h>

GTEST_TEST(UnionOfIntervals, ValidInput)
{
    auto intervals = std::vector<std::pair<int, int>>{
        {0, 3},
        {1, 1},
        {2, 4},
        {3, 4},
        {5, 7},
        {7, 8},
        {8, 11},
        {9, 11},
        {12, 14},
        {12, 16},
        {13, 15},
        {16, 17}};
    const auto expected = std::vector<std::pair<int, int>>{
        {0, 4},
        {5, 11},
        {12, 17}};
    const auto result = UnionInterval::UnionOfIntervals(intervals);
    EXPECT_EQ(expected, result);
}
