#include "compute_parity.h"

#include <gtest/gtest.h>

GTEST_TEST(ComputingParity, CountBits1)
{
    constexpr auto expected = 3;
    const auto result = ComputingParity::CountBits(0b1011);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, CountBits2)
{
    constexpr auto expected = 2;
    const auto result = ComputingParity::CountBits(0b10001000);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, Parity1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::Parity(0b1011);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, Parity2)
{
    constexpr auto expected = 0;
    const auto result = ComputingParity::Parity(0b10001000);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, ParityDropLowestBits1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::ParityDropLowestBits(0b1011);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, ParityDropLowestBits2)
{
    constexpr auto expected = 0;
    const auto result = ComputingParity::ParityDropLowestBits(0b10001000);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ComputingParity, ParityMask1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::ParityLookupTable(0b11101010);
    EXPECT_EQ(expected, result);
}
