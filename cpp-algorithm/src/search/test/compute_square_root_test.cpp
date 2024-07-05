#include "compute_square_root.h"

#include <gtest/gtest.h>

GTEST_TEST(SquareRoot, ComputeIntegerSquareRootCase1)
{
    constexpr int k = 300;
    constexpr int expected = 17;
    const int result = ComputeSquareRoot::ComputeIntegerSquareRoot(k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SquareRoot, ComputeIntegerSquareRootCase2)
{
    constexpr int k = 21;
    constexpr int expected = 4;
    const int result = ComputeSquareRoot::ComputeIntegerSquareRoot(k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(SquareRoot, ComputeIntegerSquareRootCase3)
{
    constexpr int k = 25;
    constexpr int expected = 5;
    const int result = ComputeSquareRoot::ComputeIntegerSquareRoot(k);
    EXPECT_EQ(expected, result);
}
