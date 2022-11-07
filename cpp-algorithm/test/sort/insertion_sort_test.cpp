#include "sort.h"

#include <gtest/gtest.h>

TEST(InsertionSortTest, Simple)
{
    auto seq = std::vector<int>{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    const auto sortedSeq = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const auto result = Sort::InsertionSort(seq);

    ASSERT_EQ(static_cast<int>(sortedSeq.size()), static_cast<int>(result.size()))
        << "Vectors x and y are of unequal length";

    for (int i = 0; i < static_cast<int>(result.size()); ++i)
    {
        ASSERT_EQ(sortedSeq[i], result[i])
            << "Vectors x and y differ at index " << i;
    }
}
