#include "compute_square_root.h"

#include <gtest/gtest.h>

GTEST_TEST(SquareRoot, ComputeIntegerSquareRootCase1)
{
    constexpr auto k = 300;
    constexpr auto expected = 17;
    const auto result = ComputeSquareRoot::ComputeIntegerSquareRoot(k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SquareRoot, ComputeIntegerSquareRootCase2)
{
    constexpr auto k = 21;
    constexpr auto expected = 4;
    const auto result = ComputeSquareRoot::ComputeIntegerSquareRoot(k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SquareRoot, ComputeIntegerSquareRootCase3)
{
    constexpr auto k = 25;
    constexpr auto expected = 5;
    const auto result = ComputeSquareRoot::ComputeIntegerSquareRoot(k);
    EXPECT_EQ(expected, result);
}
