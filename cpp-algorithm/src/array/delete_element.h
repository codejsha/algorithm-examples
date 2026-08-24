#ifndef CPP_ALGORITHM_DELETE_ELEMENT_H
#define CPP_ALGORITHM_DELETE_ELEMENT_H

#include <algorithm>
#include <vector>

namespace DeleteElement
{
    /**
     * \brief Delete duplicate elements in the array.
     * \param numbers input array
     * \return result array
     */
    std::vector<int> DeleteDuplicates(std::vector<int>& numbers);

    /**
     * \brief Delete duplicate elements in the array.
     * \param numbers input array
     * \return result array
     */
    std::vector<int> DeleteDuplicateElements(std::vector<int>& numbers);

    /**
     * \brief Delete specific elements in the array.
     * \param numbers input array
     * \param element specific element
     * \return result array
     */
    std::vector<int> DeleteSpecificElements(
        std::vector<int>& numbers,
        int element);
}

// ----------------------------------------------------------------------------
inline std::vector<int> DeleteElement::DeleteDuplicates(std::vector<int>& numbers)
{
    if (numbers.empty())
    {
        return {};
    }

    int write_index = 1;
    for (int i = 1; i < static_cast<int>(numbers.size()); ++i)
    {
        if (numbers[write_index - 1] != numbers[i])
        {
            numbers[write_index] = numbers[i];
            ++write_index;
        }
    }

    return std::vector<int>{numbers.begin(), numbers.begin() + write_index};
}

// ----------------------------------------------------------------------------
inline std::vector<int> DeleteElement::DeleteDuplicateElements(std::vector<int>& numbers)
{
    if (numbers.empty())
    {
        return {};
    }

    std::ranges::sort(numbers);
    numbers.erase(std::ranges::unique(numbers).begin(), numbers.end());

    return numbers;
}

// ----------------------------------------------------------------------------
inline std::vector<int> DeleteElement::DeleteSpecificElements(
    std::vector<int>& numbers,
    const int element)
{
    if (numbers.empty())
    {
        return {};
    }

    std::erase(numbers, element);
    return numbers;
}

#endif
