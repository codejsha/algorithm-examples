#include "activity_selection.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <ranges>

TEST(ActivitySelectionTest, RecursiveActivitySelection)
{
    const auto startTimes = std::vector<int>{0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    const auto endTimes = std::vector<int>{0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    const auto expectedResult = std::vector<int>{1, 4, 8, 11};

    auto result = ActivitySelection::RecursiveActivitySelector(
        startTimes, endTimes, 0, static_cast<int>(startTimes.size()));
    std::ranges::reverse(result);

    EXPECT_EQ(expectedResult, result);
}

TEST(ActivitySelectionTest, GreedyActivitySelection)
{
    const auto startTimes = std::vector<int>{1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    const auto endTimes = std::vector<int>{4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    const auto expectedResult = std::vector<int>{0, 3, 7, 10};
    auto selected = std::vector<int>{};

    const auto result = ActivitySelection::GreedyActivitySelector(startTimes, endTimes);
    EXPECT_EQ(expectedResult, result);
}
