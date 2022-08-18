#include "combination.h"

#include <gtest/gtest.h>

TEST(CombinationTest, Simple)
{
    auto seq = std::vector<int>{2, 4, 6, 8};
    constexpr auto subset_size = 2;
    std::vector<int> selected_items;

    combination::SelectItem(seq, selected_items, subset_size);
    // result:
    // 2 4
    // 2 6
    // 2 8
    // 4 6
    // 4 8
    // 6 8
}

TEST(CombinationTest, Simple2)
{
    auto seq = std::vector<int>{0, 1, 2, 3, 4, 5};
    std::vector<int> selected_items;
    constexpr auto subset_size = 2;

    combination::SelectItem(seq, selected_items, subset_size);
    // result:
    // 0 1
    // 0 2
    // 0 3
    // 0 4
    // 0 5
    // 1 2
    // 1 3
    // 1 4
    // 1 5
    // 2 3
    // 2 4
    // 2 5
    // 3 4
    // 3 5
    // 4 5
}
