#include "interval_subset_sum_problem.h"
#include "util.h"
#include <iostream>

int problem::SimpleSubsetSum(const std::vector<int>& seq)
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

int problem::SimpleSubsetSum2(const std::vector<int>& seq)
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

int problem::DivideAndConquerSubsetSum(const std::vector<int>& seq, const int low, const int high)
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

int problem::DynamicProgrammingSubsetSum(const std::vector<int>& seq)
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

int main()
{
    const auto seq = util::GenerateSequence(8, -10, 10);

    std::cout << "Sequence:" << std::endl;
    util::PrintSequence(seq);

    auto result = problem::SimpleSubsetSum(seq);
    std::cout << "Max subset sum (simple loop):" << std::endl;
    std::cout << result << std::endl;

    auto result2 = problem::SimpleSubsetSum2(seq);
    std::cout << "Max subset sum (simple loop 2):" << std::endl;
    std::cout << result2 << std::endl;

    auto result3 = problem::DivideAndConquerSubsetSum(seq, 0, static_cast<int>(seq.size() - 1));
    std::cout << "Max subset sum (divide and conquer):" << std::endl;
    std::cout << result3 << std::endl;

    auto result4 = problem::DynamicProgrammingSubsetSum(seq);
    std::cout << "Max subset sum (dynamic programming):" << std::endl;
    std::cout << result4 << std::endl;
}
