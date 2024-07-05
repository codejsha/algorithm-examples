#include "merge_two_sorted_array.h"

#include <gtest/gtest.h>

GTEST_TEST(MergeTwoSortedArray, Successful1)
{
    auto nums1 = std::vector<int>{5, 13, 17, 0, 0, 0, 0};
    constexpr int m = 3;
    const auto nums2 = std::vector<int>{3, 7, 11, 19};
    constexpr int n = 4;
    const auto merged = std::vector<int>{3, 5, 7, 11, 13, 17, 19};

    MergeTwoSortedArray::MergeTwoSortedArray(nums1, m, nums2, n);

    ASSERT_EQ(static_cast<int>(merged.size()), static_cast<int>(nums1.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(nums1.size()); ++i)
    {
        ASSERT_EQ(merged[i], nums1[i])
            << "Vectors x and y differ at index " << i;
    }
}

GTEST_TEST(MergeTwoSortedArray, Successful2)
{
    auto nums1 = std::vector<int>{1, 2, 3, 0, 0, 0};
    constexpr int m = 3;
    const auto nums2 = std::vector<int>{2, 5, 6};
    constexpr int n = 3;
    const auto merged = std::vector<int>{1, 2, 2, 3, 5, 6};

    MergeTwoSortedArray::MergeTwoSortedArray(nums1, m, nums2, n);

    ASSERT_EQ(static_cast<int>(merged.size()), static_cast<int>(nums1.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(nums1.size()); ++i)
    {
        ASSERT_EQ(merged[i], nums1[i])
            << "Vectors x and y differ at index " << i;
    }
}
