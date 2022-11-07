#include "sort.h"

#include <iostream>

std::vector<int> Sort::InsertionSort(std::vector<int>& seq)
{
    const auto size = static_cast<int>(seq.size());

    for (int index = 1; index < size; ++index)
    {
        auto key = index;
        while ((key > 0) && (seq[key] < seq[key - 1]))
        {
            std::swap(seq[key], seq[key - 1]);
            key--;
        }
    }
    return seq;
}
