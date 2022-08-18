#include "interval_subset_sum_problem.h"

#include <gtest/gtest.h>

TEST(IntervalSubsetSumTest, Simple)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected_value = 8;

    const auto result = intervalsubset::SimpleSubsetSum(seq);
    ASSERT_EQ(result, expected_value);
}

TEST(IntervalSubsetSumTest, Simple2)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected_value = 8;

    const auto result = intervalsubset::SimpleSubsetSum2(seq);
    ASSERT_EQ(result, expected_value);
}

TEST(IntervalSubsetSumTest, DivideAndConquer)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected_value = 8;

    const auto result = intervalsubset::DivideAndConquerSubsetSum(seq, 0, static_cast<int>(seq.size() - 1));
    ASSERT_EQ(result, expected_value);
}

TEST(IntervalSubsetSumTest, DynamicProgramming)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected_value = 8;

    const auto result = intervalsubset::DynamicProgrammingSubsetSum(seq);
    ASSERT_EQ(result, expected_value);
}
