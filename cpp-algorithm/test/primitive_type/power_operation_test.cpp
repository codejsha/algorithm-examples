#include "power_operation.h"

#include <gtest/gtest.h>

GTEST_TEST(PowerOperationTest, Simple1)
{
    constexpr auto expected = 0b100;
    const auto result = PowerOperation::Power(0b10, 0b10);
    EXPECT_EQ(expected, result);
}
