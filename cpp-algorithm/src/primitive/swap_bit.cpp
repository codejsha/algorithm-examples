#include "swap_bit.h"

auto SwapBit::SwapBits(long x, const int i, const int j) -> long
{
    if (((x >> i) & 1) != ((x >> j) & 1))
    {
        const auto bit_mask = (1L << i) | (1L << j);
        x ^= bit_mask;
    }
    return x;
}
