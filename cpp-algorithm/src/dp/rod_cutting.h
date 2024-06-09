#ifndef CPP_ALGORITHM_ROD_CUTTING_H
#define CPP_ALGORITHM_ROD_CUTTING_H

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
    auto CutRod(const std::map<int, int>& price, int length) -> int;

    /**
     * \brief Rod cutting algorithm with memoization that use top-down approach.
     * \param price prices for rod length
     * \param length length of a rod
     * \return the maximum revenue
     */
    auto MemoizedCutRod(const std::map<int, int>& price, int length) -> int;

    /**
     * \brief Sub procedure for rod cutting algorithm with memoization.
     * This use auxiliary array for memoization.
     * \param price prices for rod length
     * \param length length of a rod
     * \param memo memoized results
     * \return the maximum revenue
     */
    auto MemoizedCutRodAux(const std::map<int, int>& price, int length, std::vector<int>& memo) -> int;

    /**
     * \brief Rod cutting algorithm that use bottom-up approach.
     * \param price prices for rod length
     * \param length length of a rod
     * \return the maximum revenue
     */
    auto BottomUpCutRod(const std::map<int, int>& price, int length) -> int;

    /**
     * \brief Rod cutting algorithm that computes the maximum revenue and the optimal size of the first piece for given
     * rod length.
     * \param price prices for rod length
     * \param length length of a rod
     * \return the maximum revenue and the optimal size of the first piece
     */
    auto ExtendedBottomUpCutRod(const std::map<int, int>& price, int length) -> std::tuple<int, int>;
}

#endif
