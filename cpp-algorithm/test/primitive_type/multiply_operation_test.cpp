#include "multiply_operation.h"

#include <gtest/gtest.h>

TEST(MultiplyOperationTest, Simple1)
{
    constexpr auto expected = 0b1110101;
    const auto result = MultiplyOperation::Multiply(0b1101, 0b1001);
    ASSERT_EQ(expected, result);
}
