#include "rabin_karp.h"

#include <gtest/gtest.h>

GTEST_TEST(RabinKarpTest, RabinKarpMatcher1)
{
    EXPECT_EQ(std::vector{0}, RabinKarp::RabinKarpMatcher1("HelloWorld", "Hello"));
    EXPECT_EQ(std::vector<int>{}, RabinKarp::RabinKarpMatcher1("HelloWorld", "hello"));
    EXPECT_EQ(std::vector{5}, RabinKarp::RabinKarpMatcher1("HelloWorld", "World"));
    EXPECT_EQ(std::vector<int>{}, RabinKarp::RabinKarpMatcher1("HelloWorld", "world"));

    EXPECT_EQ(std::vector{3}, RabinKarp::RabinKarpMatcher1("abcabaabcabac", "abaa"));
    const auto expected = std::vector{0, 6};
    EXPECT_EQ(expected, RabinKarp::RabinKarpMatcher1("abcabaabcabac", "abc"));
}

GTEST_TEST(RabinKarpTest, RabinKarpMatcher2)
{
    EXPECT_EQ(std::vector{0}, RabinKarp::RabinKarpMatcher2("HelloWorld", "Hello"));
    EXPECT_EQ(std::vector<int>{}, RabinKarp::RabinKarpMatcher2("HelloWorld", "hello"));
    EXPECT_EQ(std::vector{5}, RabinKarp::RabinKarpMatcher2("HelloWorld", "World"));
    EXPECT_EQ(std::vector<int>{}, RabinKarp::RabinKarpMatcher2("HelloWorld", "world"));

    EXPECT_EQ(std::vector{3}, RabinKarp::RabinKarpMatcher2("abcabaabcabac", "abaa"));
    const auto expected = std::vector{0, 6};
    EXPECT_EQ(expected, RabinKarp::RabinKarpMatcher2("abcabaabcabac", "abc"));
}
