#include "combination_problem.h"
#include "util.h"
#include <iostream>

void combination::SelectItem(std::vector<int>& seq, std::vector<int>& selected_items, int count)
{
    if (count == 0)
    {
        util::PrintSequence(selected_items);
        return;
    }

    for (int i = 0; i < seq.size(); ++i)
    {
        selected_items.push_back(seq[i]);
        SelectItem(seq, selected_items, count - 1);
        selected_items.pop_back();
    }
}

int main()
{
    auto seq = util::GenerateSequence(4, 1, 100);

    std::cout << "Sequence:" << std::endl;
    util::PrintSequence(seq);

    std::cout << "Combination:" << std::endl;
    std::vector<int> selected_items;
    combination::SelectItem(seq, selected_items, 2);
}
