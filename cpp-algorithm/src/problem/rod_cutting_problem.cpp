#include "rod_cutting_problem.h"
#include <algorithm>

int rodcutting::CutRod(const std::map<int, int>& price, const int length)
{
    if (length == 0)
    {
        return 0;
    }

    auto max_revenue = std::numeric_limits<int>::min();

    for (int i = 1; i <= length; i++)
    {
        max_revenue = std::max(max_revenue, price.at(i) + CutRod(price, length - i));
    }

    return max_revenue;
}

int rodcutting::MemoizedCutRod(const std::map<int, int>& price, const int length)
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    return MemoizedCutRodAux(price, length, memo);
}

int rodcutting::MemoizedCutRodAux(const std::map<int, int>& price, const int length, std::vector<int>& memo)
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
        for (int i = 1; i <= length; i++)
        {
            max_revenue = std::max(max_revenue, price.at(i) + MemoizedCutRodAux(price, length - i, memo));
        }
    }

    memo[length] = max_revenue;

    return max_revenue;
}

int rodcutting::BottomUpCutRod(const std::map<int, int>& price, const int length)
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    memo[0] = 0;

    for (int i = 1; i <= length; i++)
    {
        auto max_revenue = std::numeric_limits<int>::min();
        for (int j = 1; j <= i; j++)
        {
            max_revenue = std::max(max_revenue, price.at(j) + memo[i - j]);
        }
        memo[i] = max_revenue;
    }

    return memo[length];
}
