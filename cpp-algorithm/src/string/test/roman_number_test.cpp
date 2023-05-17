#include "roman_number.h"

#include <gtest/gtest.h>

GTEST_TEST(RomanNumber, VerifyRomanString)
{
    ASSERT_FALSE(RomanNumber::VerifyRomanString("IXC"));
    ASSERT_FALSE(RomanNumber::VerifyRomanString("CDM"));
}

GTEST_TEST(RomanNumber, RomanStringToInteger)
{
    EXPECT_EQ(59, RomanNumber::RomanStringToInteger("LIX"));
}
