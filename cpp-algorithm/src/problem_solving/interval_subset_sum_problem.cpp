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
            for (int loopIndex = prev; loopIndex <= next; ++loopIndex)
            {
                sum += seq[loopIndex];
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
    const auto leftMax = DivideAndConquerSubsetSum(seq, low, mid);
    const auto rightMax = DivideAndConquerSubsetSum(seq, mid + 1, high);

    // cross subset
    auto leftCrossMax = 0;
    auto rightCrossMax = 0;
    auto leftSum = 0;
    auto rightSum = 0;
    for (int index = mid; index >= low; --index)
    {
        leftSum += seq[index];
        leftCrossMax = std::max(leftCrossMax, leftSum);
    }
    for (int index = mid + 1; index <= high; ++index)
    {
        rightSum += seq[index];
        rightCrossMax = std::max(rightCrossMax, rightSum);
    }

    return std::max(std::max(leftMax, rightMax), leftCrossMax + rightCrossMax);
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
