#include "combination.h"
#include "util.h"

void combination::SelectItem(std::vector<int>& seq, std::vector<int>& selected_items, const int count)
{
    const auto size = static_cast<int>(seq.size());

    if (count == 0)
    {
        if (selected_items[0] < selected_items[1])
        {
            util::PrintSequence(selected_items);
        }
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        selected_items.push_back(seq[i]);
        SelectItem(seq, selected_items, count - 1);
        selected_items.pop_back();
    }
}