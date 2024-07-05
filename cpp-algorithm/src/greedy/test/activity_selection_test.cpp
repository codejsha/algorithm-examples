#include "activity_selection.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(ActivitySelection, RecursiveActivitySelection)
{
    const auto start_times = std::vector<int>{0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    const auto end_times = std::vector<int>{0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    const auto expected = std::vector<int>{1, 4, 8, 11};
    constexpr int index = 0;
    const int size = static_cast<int>(start_times.size());

    auto result = ActivitySelection::RecursiveActivitySelector(start_times, end_times, index, size);
    std::ranges::reverse(result);

    EXPECT_EQ(expected, result);
}

GTEST_TEST(ActivitySelection, GreedyActivitySelection)
{
    const auto start_times = std::vector<int>{1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    const auto end_times = std::vector<int>{4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    const auto expected = std::vector<int>{0, 3, 7, 10};

    const auto result = ActivitySelection::GreedyActivitySelector(start_times, end_times);
    EXPECT_EQ(expected, result);
}
