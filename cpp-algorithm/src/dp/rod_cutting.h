#ifndef CPP_ALGORITHM_ROD_CUTTING_H
#define CPP_ALGORITHM_ROD_CUTTING_H

#include <algorithm>
#include <limits>
#include <map>
#include <vector>

namespace RodCutting
{
    /**
     * \brief Rod cutting algorithm to call recursively.
     * \param price prices for rod length
     * \param length length of a rod
     * \return the maximum revenue
     */
    int CutRod(
        const std::map<int, int>& price,
        int length);

    /**
     * \brief Rod cutting algorithm with memoization that use top-down approach.
     * \param price prices for rod length
     * \param length length of a rod
     * \return the maximum revenue
     */
    int MemoizedCutRod(
        const std::map<int, int>& price,
        int length);

    /**
     * \brief Sub procedure for rod cutting algorithm with memoization.
     * This use auxiliary array for memoization.
     * \param price prices for rod length
     * \param length length of a rod
     * \param memo memoized results
     * \return the maximum revenue
     */
    int MemoizedCutRodAux(
        const std::map<int, int>& price,
        int length,
        std::vector<int>& memo);

    /**
     * \brief Rod cutting algorithm that use bottom-up approach.
     * \param price prices for rod length
     * \param length length of a rod
     * \return the maximum revenue
     */
    int BottomUpCutRod(
        const std::map<int, int>& price,
        int length);

    /**
     * \brief Rod cutting algorithm that computes the maximum revenue and the optimal size of the first piece for given
     * rod length.
     * \param price prices for rod length
     * \param length length of a rod
     * \return the maximum revenue and the optimal size of the first piece
     */
    std::tuple<int, int> ExtendedBottomUpCutRod(
        const std::map<int, int>& price,
        int length);
}

// ----------------------------------------------------------------------------
inline int RodCutting::CutRod(
    const std::map<int, int>& price,
    const int length)
{
    if (length == 0)
    {
        return 0;
    }

    int max_revenue = std::numeric_limits<int>::min();

    for (int i = 1; i <= length; ++i)
    {
        max_revenue = std::max(max_revenue, price.at(i) + CutRod(price, length - i));
    }

    return max_revenue;
}

// ----------------------------------------------------------------------------
inline int RodCutting::MemoizedCutRod(
    const std::map<int, int>& price,
    const int length)
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    return MemoizedCutRodAux(price, length, memo);
}

// ----------------------------------------------------------------------------
inline int RodCutting::MemoizedCutRodAux(
    const std::map<int, int>& price,
    const int length,
    std::vector<int>& memo)
{
    int max_revenue = std::numeric_limits<int>::min();

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

// ----------------------------------------------------------------------------
inline int RodCutting::BottomUpCutRod(
    const std::map<int, int>& price,
    const int length)
{
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    memo[0] = 0;

    for (int i = 1; i <= length; ++i)
    {
        int max_revenue = std::numeric_limits<int>::min();
        for (int j = 1; j <= i; ++j)
        {
            max_revenue = std::max(max_revenue, price.at(j) + memo[i - j]);
        }
        memo[i] = max_revenue;
    }

    return memo[length];
}

// ----------------------------------------------------------------------------
inline std::tuple<int, int> RodCutting::ExtendedBottomUpCutRod(
    const std::map<int, int>& price,
    const int length)
{
    // the memoization of the max revenue
    std::vector<int> memo(static_cast<int>(price.size()) + 1, -1);
    memo[0] = 0;

    // the optimal size of the first piece to cut off
    std::vector<int> optimal_first_piece(static_cast<int>(price.size()) + 1, -1);

    for (int i = 1; i <= length; ++i)
    {
        int max_revenue = std::numeric_limits<int>::min();
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

#endif
