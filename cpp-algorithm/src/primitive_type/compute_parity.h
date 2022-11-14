#ifndef CPP_ALGORITHM_COMPUTE_PARITY_H
#define CPP_ALGORITHM_COMPUTE_PARITY_H

#include <array>

namespace ComputingParity
{
    /// @brief Count the number of bits that are set to 1.
    /// @param x input number
    /// @return count of 1s
    short CountBits(unsigned int x);

    /// @brief Compute parity of word.
    /// @param x input number
    /// @return parity of word
    short Parity(unsigned long long x);

    /// @brief Compute parity by dropping the lowest set bit.
    /// @param x input number
    /// @return parity of word
    short ParityDropLowestBits(unsigned long long x);

    /// @brief Compute parity by caching the results.
    /// @param x input number
    /// @return parity of word
    short ParityLookupTable(unsigned long long x);

    // TODO: ParityXor
    short ParityXor(unsigned long long x);
}

#endif
