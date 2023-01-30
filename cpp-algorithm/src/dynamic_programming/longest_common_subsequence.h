#ifndef CPP_ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_H
#define CPP_ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_H

#include <gsl/gsl_matrix.h>
#include <string>
#include <tuple>

namespace CommonSubsequence
{
    /// @brief Compute the length of an LCS of two sequences
    /// @param seq1 string sequence 1
    /// @param seq2 string sequence 2
    /// @return length and direction matrices
    auto LongestCommonSubsequenceLength(const std::string& seq1, const std::string& seq2)
        -> std::tuple<gsl_matrix_int*, gsl_matrix_char*>;

    /// @brief Constructing an LCS from the length matrix
    /// @param seq1 string sequence 1
    /// @param direction_matrix direction matrix
    /// @param length1 length of the string sequence 1
    /// @param length2 length of the string sequence 2
    /// @param result LCS string
    void LongestCommonSubsequence(const std::string& seq1, const gsl_matrix_char* direction_matrix,
        int length1, int length2, std::string& result);

    /// @brief Print table of LCS lengths
    /// @param seq1 string sequence 1
    /// @param seq2 string sequence 2
    /// @param direction_matrix direction matrix
    void PrintOptimalMatrix(const std::string& seq1, const std::string& seq2,
        const gsl_matrix_char* direction_matrix);
}

#endif
