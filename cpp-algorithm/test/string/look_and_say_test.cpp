#include "look_and_say.h"

#include <gtest/gtest.h>

GTEST_TEST(LookAndSayTest, LookAndSayProblem1)
{
    EXPECT_EQ("11", LookAndSay::LookAndSayProblem("1"));
    EXPECT_EQ("21", LookAndSay::LookAndSayProblem("11"));
    EXPECT_EQ("1211", LookAndSay::LookAndSayProblem("21"));
    EXPECT_EQ("111221", LookAndSay::LookAndSayProblem("1211"));
    EXPECT_EQ("312211", LookAndSay::LookAndSayProblem("111221"));
    EXPECT_EQ("13112221", LookAndSay::LookAndSayProblem("312211"));
    EXPECT_EQ("1113213211", LookAndSay::LookAndSayProblem("13112221"));
}
