#include "longest_common_subsequence.h"

#include <gsl/gsl_matrix.h>
#include <gtest/gtest.h>

TEST(LongestCommonSebsequenceTest, DynamicProgramming)
{
    const auto seq1 = std::string("ABCBDAB");
    const auto seq2 = std::string("BDCABA");
    const auto expected = std::string("BCBA");

    const auto seqLength1 = static_cast<int>(seq1.length());
    const auto seqLength2 = static_cast<int>(seq2.length());

    const auto matrix = CommonSubsequence::LongestCommonSubsequenceLength(seq1, seq2);
    CommonSubsequence::PrintOptimalMatrix(seq1, seq2, std::get<1>(matrix));
    auto result = std::string{};
    CommonSubsequence::LongestCommonSubsequence(seq1, std::get<1>(matrix),
        seqLength1, seqLength2, result);

    ASSERT_EQ(expected, result);
}
