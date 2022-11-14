#include "sort.h"

#include <gtest/gtest.h>

GTEST_TEST(SelectionSortTest, SelectionSort)
{
    auto seq = std::vector<int>{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    const auto sorted_seq = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const auto result = Sort::SelectionSort(seq);

    ASSERT_EQ(static_cast<int>(sorted_seq.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (int i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(sorted_seq[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}
