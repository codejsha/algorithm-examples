#include "merge_sorted_array.h"

#include <gtest/gtest.h>

GTEST_TEST(MergeSortedArray, MergeSortedArray)
{
    std::vector<int> arr1 = {1, 3, 5, 7, 9};
    std::vector<int> arr2 = {2, 4, 6, 8, 10};
    std::vector<int> arr3 = {5, 10};

    std::priority_queue<int> expected;
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

    auto result = MergeSortedArray::MergeSortedArray(arr1, arr2, arr3);

    for (auto i = 0; i < static_cast<int>(expected.size()); ++i)
    {
        EXPECT_EQ(expected.top(), result.top());
        expected.pop();
        result.pop();
    }
}
