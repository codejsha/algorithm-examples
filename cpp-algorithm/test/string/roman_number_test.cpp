#include "roman_number.h"

#include <gtest/gtest.h>

GTEST_TEST(RomanNumberTest, VerifyRomanString)
{
    ASSERT_FALSE(RomanNumber::VerifyRomanString("IXC"));
    ASSERT_FALSE(RomanNumber::VerifyRomanString("CDM"));
}

GTEST_TEST(RomanNumberTest, RomanStringToInteger)
{
    EXPECT_EQ(59, RomanNumber::RomanStringToInteger("LIX"));
}
