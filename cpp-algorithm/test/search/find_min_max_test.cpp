#include "find_min_max.h"

#include <gtest/gtest.h>

GTEST_TEST(FindMinMax, FindMinMax)
{
    const auto array = std::vector{3, 2, 5, 1, 2, 4};
    constexpr auto expected_min = 1;
    constexpr auto expected_max = 5;
    const auto [min, max] = FindMinMax::FindMinMax(array);
    EXPECT_EQ(expected_min, min);
    EXPECT_EQ(expected_max, max);
}
