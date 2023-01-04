#include "merge_sorted_array.h"

#include <gtest/gtest.h>

GTEST_TEST(MergeSortedArray, MergeSortedArray)
{
    auto arr1 = std::vector{1, 3, 5, 7, 9};
    auto arr2 = std::vector{2, 4, 6, 8, 10};
    auto arr3 = std::vector{5, 10};

    auto expected = std::priority_queue<int>{};
    expected.push(1);
    expected.push(2);
    expected.push(3);
    expected.push(4);
    expected.push(5);
    expected.push(5);
    expected.push(6);
    expected.push(7);
    expected.push(8);
    expected.push(9);
    expected.push(10);
    expected.push(10);

    auto queue = std::priority_queue<int>{};
    auto result = MergeSortedArray::MergeSortedArray(
        queue, arr1, arr2, arr3);

    for (auto i = 0; i < static_cast<int>(expected.size()); ++i)
    {
        EXPECT_EQ(expected.top(), result.top());
        expected.pop();
        result.pop();
    }
}
