#include "compute_parity.h"

#include <array>

std::array<short, 1 << 16> BuildTable()
{
    std::array<short, 1 << 16> result{};
    for (int i = 0; i < (1 << 16); ++i)
    {
        result[i] = ComputingParity::Parity(i);
    }
    return result;
}

short ComputingParity::CountBits(unsigned int x)
{
    short num_bits = 0;
    while (x)
    {
        num_bits += x & 1;
        x >>= 1;
    }
    return num_bits;
}

short ComputingParity::Parity(unsigned long long x)
{
    short result = 0;
    while (x)
    {
        result ^= (x & 1);
        x >>= 1;
    }
    return result;
}

short ComputingParity::ParityDropLowestBits(unsigned long long x)
{
    short result = 0;
    while (x)
    {
        result ^= 1;
        x &= (x - 1);
    }
    return result;
}

short ComputingParity::ParityLookupTable(const unsigned long long x)
{
    constexpr int mask_size = 16;
    constexpr int bit_mask = 0xFFFF;
    static std::array<short, 1 << 16> precomputed_parity = BuildTable();

    return precomputed_parity[x >> (3 * mask_size)]
           ^ precomputed_parity[(x >> (2 * mask_size)) & bit_mask]
           ^ precomputed_parity[(x >> mask_size) & bit_mask]
           ^ precomputed_parity[x & bit_mask];
}

short ComputingParity::ParityXor(unsigned long long x)
{
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}
