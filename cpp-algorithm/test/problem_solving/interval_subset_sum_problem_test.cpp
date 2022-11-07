#include "interval_subset_sum_problem.h"

#include <gtest/gtest.h>

TEST(IntervalSubsetSumTest, Simple)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expectedValue = 8;

    const auto result = IntervalSubset::SimpleSubsetSum(seq);
    ASSERT_EQ(expectedValue, result);
}

TEST(IntervalSubsetSumTest, Simple2)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expectedValue = 8;

    const auto result = IntervalSubset::SimpleSubsetSum2(seq);
    ASSERT_EQ(expectedValue, result);
}

TEST(IntervalSubsetSumTest, DivideAndConquer)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expectedValue = 8;

    const auto result = IntervalSubset::DivideAndConquerSubsetSum(seq, 0, static_cast<int>(seq.size() - 1));
    ASSERT_EQ(expectedValue, result);
}

TEST(IntervalSubsetSumTest, DynamicProgramming)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expectedValue = 8;

    const auto result = IntervalSubset::DynamicProgrammingSubsetSum(seq);
    ASSERT_EQ(expectedValue, result);
}
