#include "swap_bit.h"

long SwapBit::SwapBits(long x, const int i, const int j)
{
    if (((x >> i) & 1) != ((x >> j) & 1))
    {
        const auto bitMask = (1L << i) | (1L << j);
        x ^= bitMask;
    }
    return x;
}
