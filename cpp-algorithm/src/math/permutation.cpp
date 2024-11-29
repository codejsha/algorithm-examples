#include "permutation.h"

#include <algorithm>
#include <iostream>

void Permutation::Permutation(const std::string& str, const std::string& prefix)
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

auto Permutation::ApplyPermutationWithAdditionalSpace(const std::vector<int>& permutation, const std::vector<char>& arr)
    -> std::vector<char>
{
    std::vector<char> result(arr.size());
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        result[permutation[i]] = arr[i];
    }
    return result;
}

auto Permutation::ApplyPermutationBySwap(std::vector<int>& permutation, std::vector<char>& arr) -> std::vector<char>
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

auto Permutation::InversePermutation(const std::vector<int>& permutation, const std::vector<char>& arr)
    -> std::vector<int>
{
    std::vector<int> result(arr.size());
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        result[permutation[i]] = i;
    }
    return result;
}

auto Permutation::NextPermutation(std::vector<int>& permutation) -> std::vector<int>
{
    const auto inversionPoint = std::is_sorted_until(permutation.rbegin(), permutation.rend());
    if (inversionPoint == permutation.rend())
    {
        return {};
    }

    const auto leastUpperBound = std::upper_bound(permutation.rbegin(), inversionPoint, *inversionPoint);

    std::iter_swap(inversionPoint, leastUpperBound);
    std::reverse(permutation.rbegin(), inversionPoint);

    return permutation;
}

auto Permutation::PreviousPermutation(std::vector<int>& permutation) -> std::vector<int>
{
    const auto inversionPoint = std::is_sorted_until(permutation.rbegin(), permutation.rend(), std::greater<>());
    if (inversionPoint == permutation.rend())
    {
        return {};
    }

    const auto leastUpperBound = std::upper_bound(permutation.rbegin(), inversionPoint, *inversionPoint, std::greater<>());

    std::iter_swap(inversionPoint, leastUpperBound);
    std::reverse(permutation.rbegin(), inversionPoint);

    return permutation;
}

auto Permutation::KthPermutation(std::vector<int>& permutation, int k) -> std::vector<int>
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
