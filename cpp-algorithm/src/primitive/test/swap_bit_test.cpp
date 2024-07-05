#include "swap_bit.h"

#include <gtest/gtest.h>

GTEST_TEST(SwapBit, SwapBits1)
{
    constexpr long expected = 0b00001011;
    const long result = SwapBit::SwapBits(0b01001001, 1, 6);
    EXPECT_EQ(expected, result);
}
