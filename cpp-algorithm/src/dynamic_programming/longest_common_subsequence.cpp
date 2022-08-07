#include "longest_common_subsequence.h"

#include <iostream>

auto CommonSubsequence::LongestCommonSubsequenceLength(const std::string& seq1, const std::string& seq2)
    -> std::tuple<gsl_matrix_int*, gsl_matrix_char*>
{
    const auto seqLength1 = static_cast<int>(seq1.length());
    const auto seqLength2 = static_cast<int>(seq2.length());

    auto lengthMatrix = gsl_matrix_int_calloc(seqLength1 + 1, seqLength2 + 1);
    gsl_matrix_int_set_zero(lengthMatrix);
    auto directionMatrix = gsl_matrix_char_alloc(seqLength1 + 1, seqLength2 + 1);
    gsl_matrix_char_set_all(directionMatrix, '.');

    for (int i = 1; i <= seqLength1; ++i)
    {
        for (int j = 1; j <= seqLength2; ++j)
        {
            if (seq1[i - 1] == seq2[j - 1])
            {
                gsl_matrix_int_set(lengthMatrix, i, j, gsl_matrix_int_get(lengthMatrix, i - 1, j - 1) + 1);
                gsl_matrix_char_set(directionMatrix, i, j, '\\');
            }
            else
            {
                if (gsl_matrix_int_get(lengthMatrix, i - 1, j) >= gsl_matrix_int_get(lengthMatrix, i, j - 1))
                {
                    gsl_matrix_int_set(lengthMatrix, i, j, gsl_matrix_int_get(lengthMatrix, i - 1, j));
                    gsl_matrix_char_set(directionMatrix, i, j, '|');
                }
                else
                {
                    gsl_matrix_int_set(lengthMatrix, i, j, gsl_matrix_int_get(lengthMatrix, i, j - 1));
                    gsl_matrix_char_set(directionMatrix, i, j, '-');
                }
            }
        }
    }

    return std::make_tuple(lengthMatrix, directionMatrix);
}

auto CommonSubsequence::LongestCommonSubsequence(const std::string& seq1, const gsl_matrix_char* directionMatrix,
    const int length1, const int length2, std::string& result) -> void
{
    if ((length1 == 0) || (length2 == 0))
    {
        return;
    }

    if (gsl_matrix_char_get(directionMatrix, length1, length2) == '\\')
    {
        LongestCommonSubsequence(seq1, directionMatrix, length1 - 1, length2 - 1, result);
        result = result + seq1[length1 - 1];
    }
    else if (gsl_matrix_char_get(directionMatrix, length1, length2) == '|')
    {
        LongestCommonSubsequence(seq1, directionMatrix, length1 - 1, length2, result);
    }
    else
    {
        LongestCommonSubsequence(seq1, directionMatrix, length1, length2 - 1, result);
    }
}

auto CommonSubsequence::PrintOptimalMatrix(const std::string& seq1, const std::string& seq2,
    const gsl_matrix_char* directionMatrix) -> void
{
    const auto seqLength1 = static_cast<int>(seq1.length());
    const auto seqLength2 = static_cast<int>(seq2.length());

    std::cout << "  j ";
    for (int i = 0; i < seqLength2; ++i)
    {
        std::cout << seq2[i] << " ";
    }
    std::cout << std::endl;

    for (auto i = 0; i <= seqLength1; ++i)
    {
        if (i == 0)
        {
            std::cout << "i ";
        }
        else
        {
            std::cout << seq1[i - 1] << " ";
        }

        for (auto j = 0; j <= seqLength2; ++j)
        {
            std::cout << gsl_matrix_char_get(directionMatrix, i, j) << " ";
        }
        std::cout << std::endl;
    }
}
