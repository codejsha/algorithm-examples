#include "palindrome.h"

#include <gtest/gtest.h>

GTEST_TEST(PalindromeTest, IsPalindromic1)
{
    ASSERT_TRUE(Palindrome::IsPalindromic1("kayak"));
    ASSERT_TRUE(Palindrome::IsPalindromic1("deed"));
    ASSERT_TRUE(Palindrome::IsPalindromic1("rotator"));
    ASSERT_TRUE(Palindrome::IsPalindromic1("noon"));
}

GTEST_TEST(PalindromeTest, IsPalindromic2)
{
    ASSERT_TRUE(Palindrome::IsPalindromic2("kayak"));
    ASSERT_TRUE(Palindrome::IsPalindromic2("deed"));
    ASSERT_TRUE(Palindrome::IsPalindromic2("rotator"));
    ASSERT_TRUE(Palindrome::IsPalindromic2("noon"));
}
