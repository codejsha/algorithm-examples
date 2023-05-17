#include "intersect_two_sorted_array.h"

#include <gtest/gtest.h>

GTEST_TEST(IntersectTwoSortedArrayLoopJoin, Successful1)
{
    const auto nums1 = std::vector<int>{2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
    const auto nums2 = std::vector<int>{5, 5, 6, 8, 8, 9, 10, 10};
    const auto intersect = std::vector<int>{5, 6, 8};

    const auto result = IntersectTwoSortedArrayLoopJoin(nums1, nums2);

    ASSERT_EQ(static_cast<int>(intersect.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(intersect[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}

GTEST_TEST(IntersectTwoSortedArrayLoopJoin, Successful2)
{
    const auto nums1 = std::vector<int>{2, 3, 3, 5, 7, 11};
    const auto nums2 = std::vector<int>{3, 3, 7, 15, 31};
    const auto intersect = std::vector<int>{3, 7};

    const auto result = IntersectTwoSortedArrayLoopJoin(nums1, nums2);

    ASSERT_EQ(static_cast<int>(intersect.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(intersect[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}

GTEST_TEST(IntersectTwoSortedArrayLoopJoin2, Successful1)
{
    const auto nums1 = std::vector<int>{2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
    const auto nums2 = std::vector<int>{5, 5, 6, 8, 8, 9, 10, 10};
    const auto intersect = std::vector<int>{5, 6, 8};

    const auto result = IntersectTwoSortedArrayLoopJoin2(nums1, nums2);

    ASSERT_EQ(static_cast<int>(intersect.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(intersect[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}

GTEST_TEST(IntersectTwoSortedArrayLoopJoin2, Successful2)
{
    const auto nums1 = std::vector<int>{2, 3, 3, 5, 7, 11};
    const auto nums2 = std::vector<int>{3, 3, 7, 15, 31};
    const auto intersect = std::vector<int>{3, 7};

    const auto result = IntersectTwoSortedArrayLoopJoin2(nums1, nums2);

    ASSERT_EQ(static_cast<int>(intersect.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(intersect[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}

GTEST_TEST(IntersectTwoSortedArray, Successful1)
{
    const auto nums1 = std::vector<int>{2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
    const auto nums2 = std::vector<int>{5, 5, 6, 8, 8, 9, 10, 10};
    const auto intersect = std::vector<int>{5, 6, 8};

    const auto result = IntersectTwoSortedArray(nums1, nums2);

    ASSERT_EQ(static_cast<int>(intersect.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(intersect[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}

GTEST_TEST(IntersectTwoSortedArray, Successful2)
{
    const auto nums1 = std::vector<int>{2, 3, 3, 5, 7, 11};
    const auto nums2 = std::vector<int>{3, 3, 7, 15, 31};
    const auto intersect = std::vector<int>{3, 7};

    const auto result = IntersectTwoSortedArray(nums1, nums2);

    ASSERT_EQ(static_cast<int>(intersect.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (auto i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(intersect[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}
