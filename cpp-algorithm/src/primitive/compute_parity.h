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
    short CountBits(unsigned int x);

    /**
     * \brief Compute parity of word.
     * \param x input number
     * \return parity of word
     */
    short Parity(unsigned long long x);

    /**
     * \brief Compute parity by dropping the lowest set bit.
     * \param x input number
     * \return parity of word
     */
    short ParityDropLowestBits(unsigned long long x);

    /**
     * \brief Compute parity by caching the results.
     * \param x input number
     * \return parity of word
     */
    short ParityLookupTable(unsigned long long x);

    // TODO: Implement ParityLookupTableXor
    short ParityXor(unsigned long long x);
}

// ----------------------------------------------------------------------------
inline short ComputingParity::CountBits(unsigned int x)
{
    short num_bits = 0;
    while (x)
    {
        num_bits += x & 1;
        x >>= 1;
    }
    return num_bits;
}

// ----------------------------------------------------------------------------
inline short ComputingParity::Parity(unsigned long long x)
{
    short result = 0;
    while (x)
    {
        result ^= (x & 1);
        x >>= 1;
    }
    return result;
}

// ----------------------------------------------------------------------------
inline short ComputingParity::ParityDropLowestBits(unsigned long long x)
{
    short result = 0;
    while (x)
    {
        result ^= 1;
        x &= (x - 1);
    }
    return result;
}

// ----------------------------------------------------------------------------
inline std::array<short, 1 << 16> BuildTable()
{
    std::array<short, 1 << 16> result{};
    for (int i = 0; i < (1 << 16); ++i)
    {
        result[i] = ComputingParity::Parity(i);
    }
    return result;
}

// ----------------------------------------------------------------------------
inline short ComputingParity::ParityLookupTable(const unsigned long long x)
{
    constexpr int mask_size = 16;
    constexpr int bit_mask = 0xFFFF;
    static std::array<short, 1 << 16> precomputed_parity = BuildTable();

    return precomputed_parity[x >> (3 * mask_size)]
           ^ precomputed_parity[(x >> (2 * mask_size)) & bit_mask]
           ^ precomputed_parity[(x >> mask_size) & bit_mask]
           ^ precomputed_parity[x & bit_mask];
}

#endif
