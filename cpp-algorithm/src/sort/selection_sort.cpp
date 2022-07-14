#include "sort.h"
#include "util.h"
#include <iostream>
#include <vector>

std::vector<int> sort::SelectionSort(std::vector<int>& seq)
{
    for (int prev = 0; prev < seq.size(); ++prev)
    {
        auto min_index = prev;
        for (int next = prev + 1; next < seq.size(); ++next)
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

int main()
{
    auto seq = util::GenerateSequence(5, 1, 100);

    std::cout << "Sequence:" << std::endl;
    util::PrintSequence(seq);

    const auto result = sort::SelectionSort(seq);
    std::cout << "Selection sort:" << std::endl;
    util::PrintSequence(result);
}
