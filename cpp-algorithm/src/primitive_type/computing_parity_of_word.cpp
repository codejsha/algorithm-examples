#include "computing_parity_of_word.h"

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
    short numBits = 0;
    while (x)
    {
        numBits += x & 1;
        x >>= 1;
    }
    return numBits;
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

short ComputingParity::ParityMask(const unsigned long long x)
{
    constexpr int maskSize = 16;
    constexpr int bitMask = 0xFFFF;
    static std::array<short, 1 << 16> precomputedParity = BuildTable();

    return precomputedParity[x >> (3 * maskSize)]
           ^ precomputedParity[(x >> (2 * maskSize)) & bitMask]
           ^ precomputedParity[(x >> maskSize) & bitMask]
           ^ precomputedParity[x & bitMask];
}

