#include "rod_cutting.h"

#include <algorithm>
#include <limits>

auto RodCutting::CutRod(const std::map<int, int>& price, const int length) -> int
{
    if (length == 0)
    {
        return 0;
    }

    auto max_revenue = std::numeric_limits<int>::min();

    for (int i = 1; i <= length; ++i)
    {
        max_revenue = std::max(max_revenue, price.at(i) + CutRod(price, length - i));
    }

    return max_revenue;
}

auto RodCutting::MemoizedCutRod(const std::map<int, int>& price, const int length) -> int
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    return MemoizedCutRodAux(price, length, memo);
}

auto RodCutting::MemoizedCutRodAux(const std::map<int, int>& price, const int length, std::vector<int>& memo) -> int
{
    auto max_revenue = std::numeric_limits<int>::min();

    if (memo[length] >= 0)
    {
        return memo[length];
    }

    if (length == 0)
    {
        max_revenue = 0;
    }
    else
    {
        for (int i = 1; i <= length; ++i)
        {
            max_revenue = std::max(max_revenue, price.at(i) + MemoizedCutRodAux(price, length - i, memo));
        }
    }

    memo[length] = max_revenue;

    return max_revenue;
}

auto RodCutting::BottomUpCutRod(const std::map<int, int>& price, const int length) -> int
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    memo[0] = 0;

    for (int i = 1; i <= length; ++i)
    {
        auto max_revenue = std::numeric_limits<int>::min();
        for (int j = 1; j <= i; ++j)
        {
            max_revenue = std::max(max_revenue, price.at(j) + memo[i - j]);
        }
        memo[i] = max_revenue;
    }

    return memo[length];
}

auto RodCutting::ExtendedBottomUpCutRod(const std::map<int, int>& price, const int length) -> std::tuple<int, int>
{
    // the memoization of the max revenue
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    memo[0] = 0;

    // the optimal size of the first piece to cut off
    std::vector<int> optimal_first_piece(static_cast<int>(price.size()) + 1, -1);

    for (int i = 1; i <= length; ++i)
    {
        auto max_revenue = std::numeric_limits<int>::min();
        for (int j = 1; j <= i; ++j)
        {
            if (max_revenue < price.at(j) + memo[i - j])
            {
                max_revenue = price.at(j) + memo[i - j];
                optimal_first_piece[i] = j;
            }
        }
        memo[i] = max_revenue;
    }

    return std::make_tuple(memo[length], optimal_first_piece[length]);
}
