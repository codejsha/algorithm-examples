#include "check_pair_of_bracket.h"

#include <gtest/gtest.h>

GTEST_TEST(PairOfBracket, CheckPairOfBracket_1)
{
    const std::string input = "()[]{}";
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_2)
{
    const std::string input = "([]){()}";
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_3)
{
    const std::string input = "[()[]{()()}]";
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_4)
{
    const std::string input = "{)";
    EXPECT_FALSE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_5)
{
    const std::string input = "[()[]{()()}";
    EXPECT_FALSE(PairOfBracket::CheckPairOfBracket(input));
}
