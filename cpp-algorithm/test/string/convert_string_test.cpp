#include "convert_string.h"

#include <gtest/gtest.h>

GTEST_TEST(ConvertStringTest, IntToString)
{
    ASSERT_EQ("423", ConvertString::IntToString(423));
    ASSERT_EQ("314", ConvertString::IntToString(314));
}

GTEST_TEST(ConvertStringTest, StringToInt)
{
    ASSERT_EQ(423, ConvertString::StringToInt("423"));
    ASSERT_EQ(314, ConvertString::StringToInt("314"));
}
