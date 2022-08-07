#ifndef CPP_ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_H
#define CPP_ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_H

#include <gsl/gsl_matrix.h>
#include <string>
#include <tuple>

namespace CommonSubsequence
{
    /// <summary>
    /// Compute the length of an LCS of two sequences
    /// </summary>
    /// <param name="seq1">string sequence 1</param>
    /// <param name="seq2">string sequence 2</param>
    /// <returns>length and direction matrices</returns>
    std::tuple<gsl_matrix_int*, gsl_matrix_char*> LongestCommonSubsequenceLength(
        const std::string& seq1, const std::string& seq2);

    /// <summary>
    /// Constructing an LCS from the length matrix
    /// </summary>
    /// <param name="seq1">string sequence 1</param>
    /// <param name="directionMatrix">direction matrix</param>
    /// <param name="length1">length of the string sequence 1</param>
    /// <param name="length2">length of the string sequence 2</param>
    /// <param name="result">LCS string</param>
    void LongestCommonSubsequence(const std::string& seq1, const gsl_matrix_char* directionMatrix,
        const int length1, const int length2, std::string& result);

    /// <summary>
    /// Print table of LCS lengths
    /// </summary>
    /// <param name="seq1">string sequence 1</param>
    /// <param name="seq2">string sequence 2</param>
    /// <param name="directionMatrix">direction matrix</param>
    void PrintOptimalMatrix(const std::string& seq1, const std::string& seq2,
        const gsl_matrix_char* directionMatrix);

} // namespace common_subsequence

#endif
