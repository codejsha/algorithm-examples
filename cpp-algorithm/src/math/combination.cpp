#include "combination.h"
#include "sequence_util.h"

void Combination::SelectItem(std::vector<int>& seq, std::vector<int>& selected_items, const int subset_size)
{
    const auto size = static_cast<int>(seq.size());

    if (subset_size == 0)
    {
        if (selected_items[0] < selected_items[1])
        {
            Util::PrintSequence(selected_items);
        }
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        selected_items.push_back(seq[i]);
        SelectItem(seq, selected_items, subset_size - 1);
        selected_items.pop_back();
    }
}
