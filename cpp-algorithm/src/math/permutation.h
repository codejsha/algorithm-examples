#ifndef CPP_ALGORITHM_PERMUTATION_H
#define CPP_ALGORITHM_PERMUTATION_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace Permutation
{
    /**
     * \brief Permutation from a given string.
     * \param str input string
     * \param prefix prefix
     */
    void Permutation(
        const std::string& str,
        const std::string& prefix);

    /**
     * \brief Permute the elements of an array.
     * \param permutation permutation array
     * \param arr array
     * \return result array
     */
    std::vector<char> ApplyPermutationWithAdditionalSpace(
        const std::vector<int>& permutation,
        const std::vector<char>& arr);

    /**
     * \brief Permute the elements of an array. (in-place)
     * \param permutation permutation array
     * \param arr array
     * \return result array
     */
    std::vector<char> ApplyPermutationBySwap(
        std::vector<int>& permutation,
        std::vector<char>& arr);

    /**
     * \brief Inverse permutation.
     * \param permutation permutation array
     * \param arr array
     * \return inverse array
     */
    std::vector<int> InversePermutation(
        const std::vector<int>& permutation,
        const std::vector<char>& arr);

    /**
     * \brief Compute the next permutation.
     * \param permutation array
     * \return next permutation array
     */
    std::vector<int> NextPermutation(
        std::vector<int>& permutation);

    /**
     * \brief Compute the previous permutation.
     * \param permutation array
     * \return previous permutation array
     */
    std::vector<int> PreviousPermutation(
        std::vector<int>& permutation);

    /**
     * \brief Compute the k-th permutation.
     * \param permutation array
     * \param k k-th index
     * \return k-th permutation array
     */
    std::vector<int> KthPermutation(
        std::vector<int>& permutation,
        int k);
}

// ----------------------------------------------------------------------------
inline void Permutation::Permutation(
    const std::string& str,
    const std::string& prefix)
{
    const int size = static_cast<int>(str.length());

    if (size == 0)
    {
        std::cout << prefix << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i)
    {
        const std::string rem = str.substr(0, i) + str.substr(i + 1);
        Permutation(rem, prefix + str[i]);
    }
}

// ----------------------------------------------------------------------------
inline std::vector<char> Permutation::ApplyPermutationWithAdditionalSpace(
    const std::vector<int>& permutation,
    const std::vector<char>& arr)
{
    std::vector<char> result(arr.size());
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        result[permutation[i]] = arr[i];
    }
    return result;
}

// ----------------------------------------------------------------------------
inline std::vector<char> Permutation::ApplyPermutationBySwap(
    std::vector<int>& permutation,
    std::vector<char>& arr)
{
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        while (permutation[i] != i)
        {
            std::swap(arr[i], arr[permutation[i]]);
            std::swap(permutation[i], permutation[permutation[i]]);
        }
    }
    return arr;
}

// ----------------------------------------------------------------------------
inline std::vector<int> Permutation::InversePermutation(
    const std::vector<int>& permutation,
    const std::vector<char>& arr)
{
    std::vector<int> result(arr.size());
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        result[permutation[i]] = i;
    }
    return result;
}

// ----------------------------------------------------------------------------
inline std::vector<int> Permutation::NextPermutation(
    std::vector<int>& permutation)
{
    const auto inversionPoint =
        std::is_sorted_until(permutation.rbegin(), permutation.rend());
    if (inversionPoint == permutation.rend())
    {
        return {};
    }

    const auto leastUpperBound =
        std::upper_bound(permutation.rbegin(), inversionPoint, *inversionPoint);

    std::iter_swap(inversionPoint, leastUpperBound);
    std::reverse(permutation.rbegin(), inversionPoint);

    return permutation;
}

// ----------------------------------------------------------------------------
inline std::vector<int> Permutation::PreviousPermutation(
    std::vector<int>& permutation)
{
    const auto inversionPoint =
        std::is_sorted_until(permutation.rbegin(), permutation.rend(), std::greater<>());
    if (inversionPoint == permutation.rend())
    {
        return {};
    }

    const auto leastUpperBound =
        std::upper_bound(permutation.rbegin(), inversionPoint, *inversionPoint, std::greater<>());

    std::iter_swap(inversionPoint, leastUpperBound);
    std::reverse(permutation.rbegin(), inversionPoint);

    return permutation;
}

// ----------------------------------------------------------------------------
inline std::vector<int> Permutation::KthPermutation(
    std::vector<int>& permutation,
    int k)
{
    std::sort(permutation.begin(), permutation.end());
    do
    {
        if (--k == 0)
        {
            return permutation;
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    return {};
}

#endif
