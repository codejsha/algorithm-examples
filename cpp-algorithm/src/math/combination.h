#ifndef CPP_ALGORITHM_COMBINATION_H
#define CPP_ALGORITHM_COMBINATION_H

#include <vector>

namespace combination
{
    /// <summary>
    /// Selection of all possible combinations of elements in a sequence.
    /// </summary>
    /// <param name="seq">sequence of elements</param>
    /// <param name="selected_items">selected elements</param>
    /// <param name="subset_size">size of the subset</param>
    void SelectItem(std::vector<int>& seq, std::vector<int>& selected_items, int subset_size);
} // namespace combination

#endif
