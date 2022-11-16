#include "run_length_encoding.h"

#include <gtest/gtest.h>

GTEST_TEST(RunLengthEncodingTest, RunLengthEncoding)
{
    EXPECT_EQ("4a1b3c2a", RunLengthEncoding::RunLengthEncoding("aaaabcccaa"));
    EXPECT_EQ("3e4f2e", RunLengthEncoding::RunLengthEncoding("eeeffffee"));
}

GTEST_TEST(RunLengthEncodingTest, RunLengthDecoding)
{
    EXPECT_EQ("aaaabcccaa", RunLengthEncoding::RunLengthDecoding("4a1b3c2a"));
    EXPECT_EQ("eeeffffee", RunLengthEncoding::RunLengthDecoding("3e4f2e"));
}
