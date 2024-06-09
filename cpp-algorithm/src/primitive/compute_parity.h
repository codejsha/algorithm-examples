#ifndef CPP_ALGORITHM_COMPUTE_PARITY_H
#define CPP_ALGORITHM_COMPUTE_PARITY_H

#include <array>

namespace ComputingParity
{
    /**
     * \brief Count the number of bits that are set to 1.
     * \param x input number
     * \return count of 1s
     */
    auto CountBits(unsigned int x) -> short;

    /**
     * \brief Compute parity of word.
     * \param x input number
     * \return parity of word
     */
    auto Parity(unsigned long long x) -> short;

    /**
     * \brief Compute parity by dropping the lowest set bit.
     * \param x input number
     * \return parity of word
     */
    auto ParityDropLowestBits(unsigned long long x) -> short;

    /**
     * \brief Compute parity by caching the results.
     * \param x input number
     * \return parity of word
     */
    auto ParityLookupTable(unsigned long long x) -> short;

    // TODO: Implement ParityLookupTableXor
    auto ParityXor(unsigned long long x) -> short;
}

#endif
