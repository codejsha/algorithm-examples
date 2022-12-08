#include "check_pair_of_bracket.h"

#include <gtest/gtest.h>

GTEST_TEST(PairOfBracketTest, CheckPairOfBracket_1)
{
    const auto input = std::string{"()[]{}"};
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracketTest, CheckPairOfBracket_2)
{
    const auto input = std::string{"([]){()}"};
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracketTest, CheckPairOfBracket_3)
{
    const auto input = std::string{"[()[]{()()}]"};
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracketTest, CheckPairOfBracket_4)
{
    const auto input = std::string{"{)"};
    EXPECT_FALSE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracketTest, CheckPairOfBracket_5)
{
    const auto input = std::string{"[()[]{()()}"};
    EXPECT_FALSE(PairOfBracket::CheckPairOfBracket(input));
}
