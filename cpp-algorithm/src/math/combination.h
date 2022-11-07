#ifndef CPP_ALGORITHM_COMBINATION_H
#define CPP_ALGORITHM_COMBINATION_H

#include <vector>

namespace Combination
{
    /// <summary>
    /// Selection of all possible combinations of elements in a sequence.
    /// </summary>
    /// <param name="seq">sequence of elements</param>
    /// <param name="selectedItems">selected elements</param>
    /// <param name="subsetSize">size of the subset</param>
    void SelectItem(std::vector<int>& seq, std::vector<int>& selectedItems, int subsetSize);
}

#endif
