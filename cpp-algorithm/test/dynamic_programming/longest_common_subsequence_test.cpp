#include "longest_common_subsequence.h"

#include <gtest/gtest.h>

GTEST_TEST(CommonSubsequence, LongestCommonSubsequenceLength)
{
    const auto seq1 = std::string("ABCBDAB");
    const auto seq2 = std::string("BDCABA");
    const auto expected = std::string("BCBA");

    const auto seq_length1 = static_cast<int>(seq1.length());
    const auto seq_length2 = static_cast<int>(seq2.length());

    const auto matrix = CommonSubsequence::LongestCommonSubsequenceLength(seq1, seq2);
    CommonSubsequence::PrintOptimalMatrix(seq1, seq2, std::get<1>(matrix));
    auto result = std::string{};
    CommonSubsequence::LongestCommonSubsequence(seq1, std::get<1>(matrix),
        seq_length1, seq_length2, result);

    EXPECT_EQ(expected, result);
}
