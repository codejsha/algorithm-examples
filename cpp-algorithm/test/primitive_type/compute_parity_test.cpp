#include "compute_parity.h"

#include <gtest/gtest.h>

GTEST_TEST(ComputeParityTest, CountBits1)
{
    constexpr auto expected = 3;
    const auto result = ComputingParity::CountBits(0b1011);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(ComputeParityTest, CountBits2)
{
    constexpr auto expected = 2;
    const auto result = ComputingParity::CountBits(0b10001000);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(ComputeParityTest, Parity1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::Parity(0b1011);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(ComputeParityTest, Parity2)
{
    constexpr auto expected = 0;
    const auto result = ComputingParity::Parity(0b10001000);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(ComputeParityTest, ParityDropLowestBits1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::ParityDropLowestBits(0b1011);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(ComputeParityTest, ParityDropLowestBits2)
{
    constexpr auto expected = 0;
    const auto result = ComputingParity::ParityDropLowestBits(0b10001000);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(ComputeParityTest, ParityMask1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::ParityLookupTable(0b11101010);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(ComputeParityTest, ParityXor1)
{
    //constexpr auto expected = 1;
    //const auto result = ComputingParity::ParityXor(0b11010111);
    //ASSERT_EQ(expected, result);
}
