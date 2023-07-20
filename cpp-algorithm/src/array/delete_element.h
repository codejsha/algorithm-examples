#ifndef CPP_ALGORITHM_DELETE_ELEMENT_H
#define CPP_ALGORITHM_DELETE_ELEMENT_H

#include <vector>

namespace DeleteElement
{
    /**
     * \brief Delete duplicate elements in the array.
     * \param numbers input array
     * \return result array
     */
    auto DeleteDuplicates(std::vector<int>& numbers) -> std::vector<int>;

    /**
     * \brief Delete duplicate elements in the array.
     * \param numbers input array
     * \return result array
     */
    auto DeleteDuplicateElements(std::vector<int>& numbers) -> std::vector<int>;

    /**
     * \brief Delete specific elements in the array.
     * \param numbers input array
     * \param element specific element
     * \return result array
     */
    auto DeleteSpecificElements(std::vector<int>& numbers, int element) -> std::vector<int>;
}

#endif
