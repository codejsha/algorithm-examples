#include "palindrome.h"

#include <gtest/gtest.h>

GTEST_TEST(Palindrome, IsPalindromic1)
{
    EXPECT_TRUE(Palindrome::IsPalindromic1("kayak"));
    EXPECT_TRUE(Palindrome::IsPalindromic1("deed"));
    EXPECT_TRUE(Palindrome::IsPalindromic1("rotator"));
    EXPECT_TRUE(Palindrome::IsPalindromic1("noon"));
}

GTEST_TEST(Palindrome, IsPalindromic2)
{
    EXPECT_TRUE(Palindrome::IsPalindromic2("kayak"));
    EXPECT_TRUE(Palindrome::IsPalindromic2("deed"));
    EXPECT_TRUE(Palindrome::IsPalindromic2("rotator"));
    EXPECT_TRUE(Palindrome::IsPalindromic2("noon"));
}
