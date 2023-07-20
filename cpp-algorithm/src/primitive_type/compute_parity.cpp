#include "compute_parity.h"

#include <array>

auto ComputingParity::CountBits(unsigned int x) -> short
{
    short num_bits = 0;
    while (x)
    {
        num_bits += x & 1;
        x >>= 1;
    }
    return num_bits;
}

auto ComputingParity::Parity(unsigned long long x) -> short
{
    short result = 0;
    while (x)
    {
        result ^= (x & 1);
        x >>= 1;
    }
    return result;
}

auto ComputingParity::ParityDropLowestBits(unsigned long long x) -> short
{
    short result = 0;
    while (x)
    {
        result ^= 1;
        x &= (x - 1);
    }
    return result;
}

auto BuildTable() -> std::array<short, 1 << 16>
{
    std::array<short, 1 << 16> result{};
    for (auto i = 0; i < (1 << 16); ++i)
    {
        result[i] = ComputingParity::Parity(i);
    }
    return result;
}

auto ComputingParity::ParityLookupTable(const unsigned long long x) -> short
{
    constexpr auto mask_size = 16;
    constexpr auto bit_mask = 0xFFFF;
    static auto precomputed_parity = BuildTable();

    return precomputed_parity[x >> (3 * mask_size)]
           ^ precomputed_parity[(x >> (2 * mask_size)) & bit_mask]
           ^ precomputed_parity[(x >> mask_size) & bit_mask]
           ^ precomputed_parity[x & bit_mask];
}
