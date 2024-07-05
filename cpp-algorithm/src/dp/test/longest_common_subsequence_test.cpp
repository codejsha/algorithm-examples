#include "longest_common_subsequence.h"

#include <gtest/gtest.h>

GTEST_TEST(CommonSubsequence, LongestCommonSubsequenceLength)
{
    const std::string seq1 = "ABCBDAB";
    const std::string seq2 = "BDCABA";
    const std::string expected = "BCBA";

    const int seq_length1 = static_cast<int>(seq1.length());
    const int seq_length2 = static_cast<int>(seq2.length());

    const auto matrix = CommonSubsequence::LongestCommonSubsequenceLength(seq1, seq2);
    CommonSubsequence::PrintOptimalMatrix(seq1, seq2, std::get<1>(matrix));
    std::string result;
    CommonSubsequence::LongestCommonSubsequence(seq1, std::get<1>(matrix), seq_length1, seq_length2, result);

    EXPECT_EQ(expected, result);
}
