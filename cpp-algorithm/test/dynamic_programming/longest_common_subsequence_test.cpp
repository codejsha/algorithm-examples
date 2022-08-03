#include "longest_common_subsequence.h"
#include <gsl/gsl_matrix.h>
#include <gtest/gtest.h>

TEST(LongestCommonSebsequenceTest, DynamicProgramming)
{
    const std::string seq1 = "ABCBDAB";
    const std::string seq2 = "BDCABA";
    const std::string expected_result = "BCBA";

    const auto seq_length1 = static_cast<int>(seq1.length());
    const auto seq_length2 = static_cast<int>(seq2.length());

    const auto matrix = common_subsequence::longest_common_subsequence_length(seq1, seq2);
    common_subsequence::print_optimal_matrix(seq1, seq2, std::get<1>(matrix));
    std::string result;
    common_subsequence::longest_common_subsequence(seq1, std::get<1>(matrix),
        seq_length1, seq_length2, result);

    ASSERT_EQ(result, expected_result);
}
