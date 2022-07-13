#include "sort.h"
#include "util.h"
#include <iostream>
#include <vector>

std::vector<int> sort::InsertionSort(std::vector<int>& seq)
{
    for (int index = 1; index < seq.size(); ++index)
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

int main()
{
    auto seq = util::GenerateSequence(5, 1, 100);

    std::cout << "Sequence:" << std::endl;
    util::PrintSequence(seq);

    std::cout << "Insertion sort:" << std::endl;
    auto result = sort::InsertionSort(seq);
    util::PrintSequence(result);
}
