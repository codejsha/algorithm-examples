#include "naive_string_match.h"

#include <gtest/gtest.h>

GTEST_TEST(NaiveStringMatchTest, NaiveStringMatcher)
{
    const auto expected = std::vector<int>{2, 4};
    const auto result = NaiveStringMatch::NaiveStringMatcher("eceyeye", "eye");
    EXPECT_EQ(expected, result);
}
