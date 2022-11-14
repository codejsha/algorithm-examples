#ifndef CPP_ALGORITHM_COMBINATION_H
#define CPP_ALGORITHM_COMBINATION_H

#include <vector>

namespace Combination
{
    /// @brief Selection of all possible combinations of elements in a sequence.
    /// @param seq sequence of elements
    /// @param selected_items selected elements
    /// @param subset_size size of the subset
    void SelectItem(std::vector<int>& seq, std::vector<int>& selected_items, int subset_size);
}

#endif
