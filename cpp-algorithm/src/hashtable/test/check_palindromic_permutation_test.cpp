#include "check_palindromic_permutation.h"

#include <gtest/gtest.h>

GTEST_TEST(IsPalindromePermutation, BasicCase1)
{
    const std::string str = "edified";
    constexpr bool expected = true;
    const bool result = CheckPalindromicPermutation::IsPalindromePermutation(str);
    EXPECT_EQ(expected, result);
}
