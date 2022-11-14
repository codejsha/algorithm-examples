#ifndef CPP_ALGORITHM_PERMUTATION_PROBLEM_H
#define CPP_ALGORITHM_PERMUTATION_PROBLEM_H

#include <string>
#include <vector>

namespace Permutation
{
    /// @brief Permutation from a given string.
    /// @param str input string
    /// @param prefix prefix
    void Permutation(const std::string& str, const std::string& prefix);

    /// @brief Permute the elements of an array.
    /// @param permutation permutation array
    /// @param arr array
    /// @return result array
    std::vector<char> ApplyPermutationWithAdditionalSpace(const std::vector<int>& permutation, const std::vector<char>& arr);

    /// @brief Permute the elements of an array. (in-place)
    /// @param permutation permutation array
    /// @param arr array
    /// @return result array
    std::vector<char> ApplyPermutationBySwap(std::vector<int>& permutation, std::vector<char>& arr);

    /// @brief Inverse permutation.
    /// @param permutation permutation array
    /// @param arr array
    /// @return inverse array
    std::vector<int> InversePermutation(const std::vector<int>& permutation, const std::vector<char>& arr);

    /// @brief Compute the next permutation.
    /// @param permutation array
    /// @return next permutation array
    std::vector<int> NextPermutation(std::vector<int>& permutation);

    /// @brief Compute the previous permutation.
    /// @param permutation array
    /// @return previous permutation array
    std::vector<int> PreviousPermutation(std::vector<int>& permutation);

    /// @brief Compute the k-th permutation.
    /// @param permutation array
    /// @param k k-th index
    /// @return k-th permutation array
    std::vector<int> KthPermutation(std::vector<int>& permutation, int k);
}

#endif
