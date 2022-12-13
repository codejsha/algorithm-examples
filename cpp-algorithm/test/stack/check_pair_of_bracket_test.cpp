#include "check_pair_of_bracket.h"

#include <gtest/gtest.h>

GTEST_TEST(PairOfBracket, CheckPairOfBracket_1)
{
    const auto input = std::string{"()[]{}"};
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_2)
{
    const auto input = std::string{"([]){()}"};
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_3)
{
    const auto input = std::string{"[()[]{()()}]"};
    EXPECT_TRUE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_4)
{
    const auto input = std::string{"{)"};
    EXPECT_FALSE(PairOfBracket::CheckPairOfBracket(input));
}

GTEST_TEST(PairOfBracket, CheckPairOfBracket_5)
{
    const auto input = std::string{"[()[]{()()}"};
    EXPECT_FALSE(PairOfBracket::CheckPairOfBracket(input));
}
