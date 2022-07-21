#include "combination_problem.h"
#include <gtest/gtest.h>

TEST(CombinationTest, Simple)
{
    auto seq = std::vector<int>{2, 4, 6, 8};
    std::vector<int> selected_items;

    combination::SelectItem(seq, selected_items, 2);
}
