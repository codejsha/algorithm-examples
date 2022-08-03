#ifndef CPP_ALGORITHM_ROD_CUTTING_PROBLEM_H
#define CPP_ALGORITHM_ROD_CUTTING_PROBLEM_H

#include <map>
#include <vector>

namespace rodcutting
{
    /// <summary>
    /// Rod cutting algorithm to call recursively.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue</returns>
    int CutRod(const std::map<int, int>& price, const int length);

    /// <summary>
    /// Rod cutting algorithm with memoization that use top-down approach.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue</returns>
    int MemoizedCutRod(const std::map<int, int>& price, const int length);

    /// <summary>
    /// Sub procedure for rod cutting algorithm with memoization.
    /// This use auxiliary array for memoization.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <param name="memo">memoized results</param>
    /// <returns>the maximum revenue</returns>
    int MemoizedCutRodAux(const std::map<int, int>& price, const int length, std::vector<int>& memo);

    /// <summary>
    /// Rod cutting algorithm that use bottom-up approach.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue</returns>
    int BottomUpCutRod(const std::map<int, int>& price, const int length);

    /// <summary>
    /// Rod cutting algorithm that computes the maximum revenue and the optimal size of the first piece for given rod length.
    /// </summary>
    /// <param name="price">prices for rod length</param>
    /// <param name="length">length of a rod</param>
    /// <returns>the maximum revenue and the optimal size of the first piece</returns>
    std::tuple<int, int> ExtendedBottomUpCutRod(const std::map<int, int>& price, const int length);
} // namespace rodcutting

#endif
