#include "check_palindromic_permutation.h"

#include <gtest/gtest.h>

GTEST_TEST(IsPalindromePermutation, BasicCase1)
{
    const auto str = "edified";
    constexpr auto expected = true;
    const auto result = CheckPalindromicPermutation::IsPalindromePermutation(str);
    EXPECT_EQ(expected, result);
}
