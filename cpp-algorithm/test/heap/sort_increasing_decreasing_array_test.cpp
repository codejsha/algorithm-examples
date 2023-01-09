#include "sort_increasing_decreasing_array.h"

#include <gtest/gtest.h>

GTEST_TEST(IncreasingDecreasingArray, SortIncreasingDecreasingArray)
{
    const auto arr = std::vector{57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
    const auto expected = std::vector{57, 131, 190, 221, 294, 339, 418, 442, 452, 493};
    const auto result = IncreasingDecreasingArray::SortIncreasingDecreasingArray(arr);
    EXPECT_EQ(expected, result);
}
