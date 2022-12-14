#include "sort.h"

auto Sort::InsertionSort(std::vector<int>& seq) -> std::vector<int>
{
    const auto size = static_cast<int>(seq.size());

    for (auto index = 1; index < size; ++index)
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
