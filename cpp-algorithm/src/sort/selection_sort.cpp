#include "sort.h"

#include <iostream>

std::vector<int> Sort::SelectionSort(std::vector<int>& seq)
{
    for (int prev = 0; prev < static_cast<int>(seq.size()); ++prev)
    {
        auto minIndex = prev;
        for (int next = prev + 1; next < static_cast<int>(seq.size()); ++next)
        {
            if (seq[minIndex] > seq[next])
            {
                minIndex = next;
            }
        }
        std::swap(seq[prev], seq[minIndex]);
    }
    return seq;
}
