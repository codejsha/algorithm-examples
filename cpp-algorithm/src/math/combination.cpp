#include "combination.h"
#include "util.h"

void Combination::SelectItem(std::vector<int>& seq, std::vector<int>& selectedItems, const int subsetSize)
{
    const auto size = static_cast<int>(seq.size());

    if (subsetSize == 0)
    {
        if (selectedItems[0] < selectedItems[1])
        {
            Util::PrintSequence(selectedItems);
        }
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        selectedItems.push_back(seq[i]);
        SelectItem(seq, selectedItems, subsetSize - 1);
        selectedItems.pop_back();
    }
}
