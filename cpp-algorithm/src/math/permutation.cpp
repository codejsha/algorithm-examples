#include "permutation.h"

#include <algorithm>
#include <iostream>

void Permutation::Permutation(const std::string& str, const std::string& prefix)
{
    const auto size = static_cast<int>(str.length());

    if (size == 0)
    {
        std::cout << prefix << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            const std::string rem = str.substr(0, i) + str.substr(i + 1);
            Permutation(rem, prefix + str[i]);
        }
    }
}

std::vector<char> Permutation::ApplyPermutationWithAdditionalSpace(const std::vector<int>& permutation, const std::vector<char>& arr)
{
    std::vector<char> result(arr.size());
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        result[permutation[i]] = arr[i];
    }
    return result;
}

std::vector<char> Permutation::ApplyPermutationBySwap(std::vector<int>& permutation, std::vector<char>& arr)
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

std::vector<int> Permutation::InversePermutation(const std::vector<int>& permutation, const std::vector<char>& arr)
{
    std::vector<int> result(arr.size());
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
    {
        result[permutation[i]] = i;
    }
    return result;
}

std::vector<int> Permutation::NextPermutation(std::vector<int>& permutation)
{
    auto inversionPoint = std::is_sorted_until(permutation.rbegin(), permutation.rend());
    if (inversionPoint == permutation.rend())
    {
        return {};
    }

    auto leastUpperBound = std::upper_bound(
        permutation.rbegin(), inversionPoint, *inversionPoint);

    std::iter_swap(inversionPoint, leastUpperBound);
    std::reverse(permutation.rbegin(), inversionPoint);

    return permutation;
}

std::vector<int> Permutation::PreviousPermutation(std::vector<int>& permutation)
{
    auto inversionPoint = std::is_sorted_until(
        permutation.rbegin(), permutation.rend(), std::greater<>());
    if (inversionPoint == permutation.rend())
    {
        return {};
    }

    auto leastUpperBound = std::upper_bound(
        permutation.rbegin(), inversionPoint, *inversionPoint, std::greater<>());

    std::iter_swap(inversionPoint, leastUpperBound);
    std::reverse(permutation.rbegin(), inversionPoint);

    return permutation;

}

std::vector<int> Permutation::KthPermutation(std::vector<int>& permutation, int k)
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
