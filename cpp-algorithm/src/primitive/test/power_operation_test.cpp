#include "power_operation.h"

#include <gtest/gtest.h>

GTEST_TEST(PowerOperation, Simple1)
{
    constexpr double expected = 0b100;
    const double result = PowerOperation::Power(0b10, 0b10);
    EXPECT_EQ(expected, result);
}
