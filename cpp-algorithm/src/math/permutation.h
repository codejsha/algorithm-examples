#ifndef CPP_ALGORITHM_PERMUTATION_H
#define CPP_ALGORITHM_PERMUTATION_H

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
    auto ApplyPermutationWithAdditionalSpace(const std::vector<int>& permutation, const std::vector<char>& arr) -> std::vector<char>;

    /// @brief Permute the elements of an array. (in-place)
    /// @param permutation permutation array
    /// @param arr array
    /// @return result array
    auto ApplyPermutationBySwap(std::vector<int>& permutation, std::vector<char>& arr) -> std::vector<char>;

    /// @brief Inverse permutation.
    /// @param permutation permutation array
    /// @param arr array
    /// @return inverse array
    auto InversePermutation(const std::vector<int>& permutation, const std::vector<char>& arr) -> std::vector<int>;

    /// @brief Compute the next permutation.
    /// @param permutation array
    /// @return next permutation array
    auto NextPermutation(std::vector<int>& permutation) -> std::vector<int>;

    /// @brief Compute the previous permutation.
    /// @param permutation array
    /// @return previous permutation array
    auto PreviousPermutation(std::vector<int>& permutation) -> std::vector<int>;

    /// @brief Compute the k-th permutation.
    /// @param permutation array
    /// @param k k-th index
    /// @return k-th permutation array
    auto KthPermutation(std::vector<int>& permutation, int k) -> std::vector<int>;
}

#endif
