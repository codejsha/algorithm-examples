#include "computing_parity_of_word.h"

#include <gtest/gtest.h>

TEST(ComputingParityTest, CountBits1)
{
    constexpr auto expected = 3;
    const auto result = ComputingParity::CountBits(0b1011);
    ASSERT_EQ(expected, result);
}

TEST(ComputingParityTest, CountBits2)
{
    constexpr auto expected = 2;
    const auto result = ComputingParity::CountBits(0b10001000);
    ASSERT_EQ(expected, result);
}

TEST(ComputingParityTest, Parity1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::Parity(0b1011);
    ASSERT_EQ(expected, result);
}

TEST(ComputingParityTest, Parity2)
{
    constexpr auto expected = 0;
    const auto result = ComputingParity::Parity(0b10001000);
    ASSERT_EQ(expected, result);
}

TEST(ComputingParityTest, ParityDropLowestBits1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::ParityDropLowestBits(0b1011);
    ASSERT_EQ(expected, result);
}

TEST(ComputingParityTest, ParityDropLowestBits2)
{
    constexpr auto expected = 0;
    const auto result = ComputingParity::ParityDropLowestBits(0b10001000);
    ASSERT_EQ(expected, result);
}

TEST(ComputingParityTest, ParityMask1)
{
    constexpr auto expected = 1;
    const auto result = ComputingParity::ParityMask(0b11101010);
    ASSERT_EQ(expected, result);
}

