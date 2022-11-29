#include "sort.h"

#include <iostream>

auto Sort::SelectionSort(std::vector<int>& seq) -> std::vector<int>
{
    for (auto prev = 0; prev < static_cast<int>(seq.size()); ++prev)
    {
        auto min_index = prev;
        for (auto next = prev + 1; next < static_cast<int>(seq.size()); ++next)
        {
            if (seq[min_index] > seq[next])
            {
                min_index = next;
            }
        }
        std::swap(seq[prev], seq[min_index]);
    }
    return seq;
}
