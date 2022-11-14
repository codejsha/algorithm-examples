#ifndef CPP_ALGORITHM_DELETE_ELEMENT_H
#define CPP_ALGORITHM_DELETE_ELEMENT_H

#include <vector>

namespace DeleteElement
{
    /// @brief Delete duplicate elements in the array.
    /// @param numbers input array
    /// @return result array
    std::vector<int> DeleteDuplicates(std::vector<int>& numbers);

    /// @brief Delete duplicate elements in the array.
    /// @param numbers input array
    /// @return result array
    std::vector<int> DeleteDuplicateElements(std::vector<int>& numbers);

    /// @brief Delete specific elements in the array.
    /// @param numbers input array
    /// @param element specific element
    /// @return result array
    std::vector<int> DeleteSpecificElements(std::vector<int>& numbers, int element);
}

#endif
