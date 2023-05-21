#include "quick_select.h"

/// @brief Partition the array around the pivot element.
/// @details To find the k-th smallest (or largest) element, partition the array into two sub lists.
/// Elements less than or equal to the pivot are on one side, and elements greater than the pivot are on the other side.
/// @param array the array to partition
/// @param left the left index of the array
/// @param right the right index of the array
/// @return the index of the pivot element
/// @note
/// Comparison Explanation:
/// - Finding k-th smallest element: This comparison is used to find the k-th smallest element:
///     @code if (arr[j] <= pivot) @endcode
/// - Finding k-th largest element: This comparison is used to find the k-th largest element:
///     @code if (arr[j] >= pivot) @endcode
auto Partition(std::vector<int>& array, const int left, const int right) -> int
{
    const auto pivot = array[right];
    auto i = left - 1;

    for (auto j = left; j < right; ++j)
    {
        if (array[j] <= pivot)
        {
            ++i;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[right]);
    return i + 1;
}

auto QuickSelect::QuickSelectAlgorithm(std::vector<int>& array, const int left, const int right, const int k) -> int
{
    if (left == right)
    {
        return array[left];
    }

    const auto pivot_index = Partition(array, left, right);
    if (k == pivot_index)
    {
        return array[pivot_index];
    }
    if (k < pivot_index)
    {
        return QuickSelectAlgorithm(array, left, pivot_index - 1, k);
    }
    return QuickSelectAlgorithm(array, pivot_index + 1, right, k);
}

auto QuickSelect::FindKthSmallestElement(std::vector<int>& array, const int k) -> int
{
    constexpr auto left = 0;
    const auto right = static_cast<int>(array.size()) - 1;
    return QuickSelectAlgorithm(array, left, right, k - 1);
}

auto QuickSelect::FindKthLargestElement(std::vector<int>& array, int k) -> int
{
    constexpr auto left = 0;
    const auto right = static_cast<int>(array.size()) - 1;
    k = static_cast<int>(array.size()) - k;
    return QuickSelectAlgorithm(array, left, right, k);
}
