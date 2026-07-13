#ifndef CPP_ALGORITHM_SWAP_BIT_H
#define CPP_ALGORITHM_SWAP_BIT_H

namespace SwapBit
{
    /**
     * \brief Swap the bits at indices i and j.
     * \param x input number
     * \param i index i
     * \param j index j
     * \return result number
     */
    long SwapBits(long x, int i, int j);
}

// ----------------------------------------------------------------------------
inline long SwapBit::SwapBits(long x, const int i, const int j)
{
    if (((x >> i) & 1) != ((x >> j) & 1))
    {
        const long bit_mask = (1L << i) | (1L << j);
        x ^= bit_mask;
    }
    return x;
}

#endif
