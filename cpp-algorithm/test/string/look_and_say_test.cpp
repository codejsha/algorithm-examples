#include "look_and_say.h"

#include <gtest/gtest.h>

GTEST_TEST(LookAndSayTest, LookAndSayProblem1)
{
    ASSERT_EQ("11", LookAndSay::LookAndSayProblem("1"));
    ASSERT_EQ("21", LookAndSay::LookAndSayProblem("11"));
    ASSERT_EQ("1211", LookAndSay::LookAndSayProblem("21"));
    ASSERT_EQ("111221", LookAndSay::LookAndSayProblem("1211"));
    ASSERT_EQ("312211", LookAndSay::LookAndSayProblem("111221"));
    ASSERT_EQ("13112221", LookAndSay::LookAndSayProblem("312211"));
    ASSERT_EQ("1113213211", LookAndSay::LookAndSayProblem("13112221"));
}
