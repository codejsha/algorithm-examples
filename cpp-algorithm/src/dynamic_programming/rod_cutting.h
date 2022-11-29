#ifndef CPP_ALGORITHM_ROD_CUTTING_H
#define CPP_ALGORITHM_ROD_CUTTING_H

#include <map>
#include <vector>

namespace RodCutting
{
    /// <summary>
    /// Rod cutting algorithm to call recursively.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue</returns>
    auto CutRod(const std::map<int, int>& price, const int length) -> int;

    /// <summary>
    /// Rod cutting algorithm with memoization that use top-down approach.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue</returns>
    auto MemoizedCutRod(const std::map<int, int>& price, const int length) -> int;

    /// <summary>
    /// Sub procedure for rod cutting algorithm with memoization.
    /// This use auxiliary array for memoization.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <param name="memo">memoized results</param>
    /// <returns>the maximum revenue</returns>
    auto MemoizedCutRodAux(const std::map<int, int>& price, const int length, std::vector<int>& memo) -> int;

    /// <summary>
    /// Rod cutting algorithm that use bottom-up approach.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue</returns>
    auto BottomUpCutRod(const std::map<int, int>& price, const int length) -> int;

    /// <summary>
    /// Rod cutting algorithm that computes the maximum revenue and the optimal size of the first piece for given rod length.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue and the optimal size of the first piece</returns>
    auto ExtendedBottomUpCutRod(const std::map<int, int>& price, const int length) -> std::tuple<int, int>;
}

#endif
