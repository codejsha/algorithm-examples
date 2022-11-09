#include "swap_bit.h"

#include <gtest/gtest.h>

TEST(SwapBitTest, SwapBits1)
{
    constexpr auto expected = 0b00001011;
    const auto result = SwapBit::SwapBits(0b01001001, 1, 6);
    ASSERT_EQ(expected, result);
}
