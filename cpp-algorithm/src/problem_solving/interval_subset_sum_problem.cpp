#include "interval_subset_sum_problem.h"

#include <iostream>

int IntervalSubset::SimpleSubsetSum(const std::vector<int>& seq)
{
    const auto size = static_cast<int>(seq.size());
    auto max = std::numeric_limits<int>::min();

    for (int prev = 0; prev < size; ++prev)
    {
        for (int next = prev; next < size; ++next)
        {
            auto sum = 0;
            for (int loop_index = prev; loop_index <= next; ++loop_index)
            {
                sum += seq[loop_index];
            }
            max = std::max(max, sum);
        }
    }

    return max;
}

int IntervalSubset::SimpleSubsetSum2(const std::vector<int>& seq)
{
    const auto size = static_cast<int>(seq.size());
    auto max = std::numeric_limits<int>::min();

    for (int prev = 0; prev < size; ++prev)
    {
        auto sum = 0;
        for (int next = prev; next < size; ++next)
        {
            sum += seq[next];
            max = std::max(max, sum);
        }
    }

    return max;
}

int IntervalSubset::DivideAndConquerSubsetSum(const std::vector<int>& seq, const int low, const int high)
{
    if (low == high)
    {
        return seq[low];
    }

    // left subset and right subset
    const auto mid = static_cast<int>(std::floor((low + high) / 2));
    const auto left_max = DivideAndConquerSubsetSum(seq, low, mid);
    const auto right_max = DivideAndConquerSubsetSum(seq, mid + 1, high);

    // cross subset
    auto left_cross_max = 0;
    auto right_cross_max = 0;
    auto left_sum = 0;
    auto right_sum = 0;
    for (int index = mid; index >= low; --index)
    {
        left_sum += seq[index];
        left_cross_max = std::max(left_cross_max, left_sum);
    }
    for (int index = mid + 1; index <= high; ++index)
    {
        right_sum += seq[index];
        right_cross_max = std::max(right_cross_max, right_sum);
    }

    return std::max(std::max(left_max, right_max), left_cross_max + right_cross_max);
}

int IntervalSubset::DynamicProgrammingSubsetSum(const std::vector<int>& seq)
{
    const auto size = static_cast<int>(seq.size());
    auto max = std::numeric_limits<int>::min();
    auto sum = 0;

    for (int index = 0; index < size; ++index)
    {
        sum = std::max(sum + seq[index], seq[index]);
        max = std::max(max, sum);
    }

    return max;
}
