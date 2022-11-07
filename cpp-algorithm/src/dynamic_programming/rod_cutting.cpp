#include "rod_cutting.h"
#include <algorithm>

int RodCutting::CutRod(const std::map<int, int>& price, const int length)
{
    if (length == 0)
    {
        return 0;
    }

    auto maxRevenue = std::numeric_limits<int>::min();

    for (int i = 1; i <= length; ++i)
    {
        maxRevenue = std::max(maxRevenue, price.at(i) + CutRod(price, length - i));
    }

    return maxRevenue;
}

int RodCutting::MemoizedCutRod(const std::map<int, int>& price, const int length)
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    return MemoizedCutRodAux(price, length, memo);
}

int RodCutting::MemoizedCutRodAux(const std::map<int, int>& price, const int length, std::vector<int>& memo)
{
    auto maxRevenue = std::numeric_limits<int>::min();

    if (memo[length] >= 0)
    {
        return memo[length];
    }

    if (length == 0)
    {
        maxRevenue = 0;
    }
    else
    {
        for (int i = 1; i <= length; ++i)
        {
            maxRevenue = std::max(maxRevenue, price.at(i) + MemoizedCutRodAux(price, length - i, memo));
        }
    }

    memo[length] = maxRevenue;

    return maxRevenue;
}

int RodCutting::BottomUpCutRod(const std::map<int, int>& price, const int length)
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    memo[0] = 0;

    for (int i = 1; i <= length; ++i)
    {
        auto maxRevenue = std::numeric_limits<int>::min();
        for (int j = 1; j <= i; ++j)
        {
            maxRevenue = std::max(maxRevenue, price.at(j) + memo[i - j]);
        }
        memo[i] = maxRevenue;
    }

    return memo[length];
}

std::tuple<int, int> RodCutting::ExtendedBottomUpCutRod(const std::map<int, int>& price, const int length)
{
    // the memoization of the max revenue
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    memo[0] = 0;

    // the optimal size of the first piece to cut off
    std::vector<int> optimalFirstPeice(static_cast<int>(price.size()) + 1, -1);

    for (int i = 1; i <= length; ++i)
    {
        auto maxRevenue = std::numeric_limits<int>::min();
        for (int j = 1; j <= i; ++j)
        {
            if (maxRevenue < price.at(j) + memo[i - j])
            {
                maxRevenue = price.at(j) + memo[i - j];
                optimalFirstPeice[i] = j;
            }
        }
        memo[i] = maxRevenue;
    }

    return std::make_tuple(memo[length], optimalFirstPeice[length]);
}
