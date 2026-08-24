#ifndef CPP_ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_H
#define CPP_ALGORITHM_LONGEST_COMMON_SUBSEQUENCE_H

#include <gsl/gsl_matrix.h>
#include <iostream>
#include <string>
#include <tuple>

namespace CommonSubsequence
{
    /**
     * \brief Compute the length of an LCS of two sequences
     * \param seq1 string sequence 1
     * \param seq2 string sequence 2
     * \return length and direction matrices
     */
    std::tuple<gsl_matrix_int*, gsl_matrix_char*> LongestCommonSubsequenceLength(
        const std::string& seq1,
        const std::string& seq2);

    /**
     * \brief Constructing an LCS from the length matrix
     * \param seq1 string sequence 1
     * \param direction_matrix direction matrix
     * \param length1 length of the string sequence 1
     * \param length2 length of the string sequence 2
     * \param result LCS string
     */
    void LongestCommonSubsequence(
        const std::string& seq1,
        const gsl_matrix_char* direction_matrix,
        int length1,
        int length2,
        std::string& result);

    /**
     * \brief Print table of LCS lengths
     * \param seq1 string sequence 1
     * \param seq2 string sequence 2
     * \param direction_matrix direction matrix
     */
    void PrintOptimalMatrix(
        const std::string& seq1,
        const std::string& seq2,
        const gsl_matrix_char* direction_matrix);
}

// ----------------------------------------------------------------------------
inline std::tuple<gsl_matrix_int*, gsl_matrix_char*> CommonSubsequence::LongestCommonSubsequenceLength(
    const std::string& seq1,
    const std::string& seq2)
{
    const int seq_length1 = static_cast<int>(seq1.length());
    const int seq_length2 = static_cast<int>(seq2.length());

    auto length_matrix = gsl_matrix_int_calloc(seq_length1 + 1, seq_length2 + 1);
    gsl_matrix_int_set_zero(length_matrix);
    auto direction_matrix = gsl_matrix_char_alloc(seq_length1 + 1, seq_length2 + 1);
    gsl_matrix_char_set_all(direction_matrix, '.');

    for (int i = 1; i <= seq_length1; ++i)
    {
        for (int j = 1; j <= seq_length2; ++j)
        {
            if (seq1[i - 1] == seq2[j - 1])
            {
                gsl_matrix_int_set(length_matrix, i, j, gsl_matrix_int_get(length_matrix, i - 1, j - 1) + 1);
                gsl_matrix_char_set(direction_matrix, i, j, '\\');
            }
            else
            {
                if (gsl_matrix_int_get(length_matrix, i - 1, j) >= gsl_matrix_int_get(length_matrix, i, j - 1))
                {
                    gsl_matrix_int_set(length_matrix, i, j, gsl_matrix_int_get(length_matrix, i - 1, j));
                    gsl_matrix_char_set(direction_matrix, i, j, '|');
                }
                else
                {
                    gsl_matrix_int_set(length_matrix, i, j, gsl_matrix_int_get(length_matrix, i, j - 1));
                    gsl_matrix_char_set(direction_matrix, i, j, '-');
                }
            }
        }
    }

    return std::make_tuple(length_matrix, direction_matrix);
}

// ----------------------------------------------------------------------------
inline void CommonSubsequence::LongestCommonSubsequence(
    const std::string& seq1,
    const gsl_matrix_char* direction_matrix,
    const int length1,
    const int length2,
    std::string& result)
{
    if ((length1 == 0) || (length2 == 0))
    {
        return;
    }

    if (gsl_matrix_char_get(direction_matrix, length1, length2) == '\\')
    {
        LongestCommonSubsequence(seq1, direction_matrix, length1 - 1, length2 - 1, result);
        result = result + seq1[length1 - 1];
    }
    else if (gsl_matrix_char_get(direction_matrix, length1, length2) == '|')
    {
        LongestCommonSubsequence(seq1, direction_matrix, length1 - 1, length2, result);
    }
    else
    {
        LongestCommonSubsequence(seq1, direction_matrix, length1, length2 - 1, result);
    }
}

// ----------------------------------------------------------------------------
inline void CommonSubsequence::PrintOptimalMatrix(
    const std::string& seq1,
    const std::string& seq2,
    const gsl_matrix_char* direction_matrix)
{
    const int seq_length1 = static_cast<int>(seq1.length());
    const int seq_length2 = static_cast<int>(seq2.length());

    std::cout << "  j ";
    for (int i = 0; i < seq_length2; ++i)
    {
        std::cout << seq2[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i <= seq_length1; ++i)
    {
        if (i == 0)
        {
            std::cout << "i ";
        }
        else
        {
            std::cout << seq1[i - 1] << " ";
        }

        for (int j = 0; j <= seq_length2; ++j)
        {
            std::cout << gsl_matrix_char_get(direction_matrix, i, j) << " ";
        }
        std::cout << std::endl;
    }
}

#endif
