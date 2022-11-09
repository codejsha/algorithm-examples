#include "divide_operation.h"

#include <gtest/gtest.h>

TEST(DivideOperationTest, Simple1)
{
    constexpr auto expected = 0b101;
    const auto result = DivideOperation::Divide(0b1011, 0b10);
    ASSERT_EQ(expected, result);
}
