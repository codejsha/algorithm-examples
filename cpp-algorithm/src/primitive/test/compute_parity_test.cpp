#include "compute_parity.h"

#include <gtest/gtest.h>

GTEST_TEST(ComputingParity, CountBits1)
{
    constexpr short expected = 3;
    const short result = ComputingParity::CountBits(0b1011);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, CountBits2)
{
    constexpr short expected = 2;
    const short result = ComputingParity::CountBits(0b10001000);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, Parity1)
{
    constexpr short expected = 1;
    const short result = ComputingParity::Parity(0b1011);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, Parity2)
{
    constexpr short expected = 0;
    const short result = ComputingParity::Parity(0b10001000);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, ParityDropLowestBits1)
{
    constexpr short expected = 1;
    const short result = ComputingParity::ParityDropLowestBits(0b1011);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, ParityDropLowestBits2)
{
    constexpr short expected = 0;
    const short result = ComputingParity::ParityDropLowestBits(0b10001000);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, ParityMask1)
{
    constexpr short expected = 1;
    const short result = ComputingParity::ParityLookupTable(0b11101010);
    EXPECT_EQ(expected, result);
}
