#include "convert_string.h"

#include <gtest/gtest.h>

GTEST_TEST(ConvertString, IntToString)
{
    EXPECT_EQ("423", ConvertString::IntToString(423));
    EXPECT_EQ("314", ConvertString::IntToString(314));
}

GTEST_TEST(ConvertString, StringToInt)
{
    EXPECT_EQ(423, ConvertString::StringToInt("423"));
    EXPECT_EQ(314, ConvertString::StringToInt("314"));
}
