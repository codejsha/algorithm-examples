#include "activity_selection.h"

#include <gtest/gtest.h>
#include <ranges>

TEST(ActivitySelectionTest, RecursiveActivitySelection)
{
    const auto start_times = std::vector<int>{0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    const auto end_times = std::vector<int>{0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    const auto expected_result = std::vector<int>{1, 4, 8, 11};

    auto result = activity_selection::recursive_activity_selector(
        start_times, end_times, 0, static_cast<int>(start_times.size()));
    std::ranges::reverse(result);

    EXPECT_EQ(result, expected_result);
}

TEST(ActivitySelectionTest, GreedyActivitySelection)
{
    const auto start_times = std::vector<int>{1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    const auto end_times = std::vector<int>{4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    const auto expected_result = std::vector<int>{0, 3, 7, 10};
    auto selected = std::vector<int>{};

    const auto result = activity_selection::greedy_activity_selector(start_times, end_times);
    EXPECT_EQ(result, expected_result);
}
