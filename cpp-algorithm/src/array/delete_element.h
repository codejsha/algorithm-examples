#ifndef CPP_ALGORITHM_DELETE_ELEMENT_H
#define CPP_ALGORITHM_DELETE_ELEMENT_H

#include <algorithm>
#include <vector>

namespace DeleteElement
{
    /**
     * \brief Remove consecutive duplicate elements from a sorted array.
     * \param numbers sorted input array
     * \return array with duplicates removed
     */
    std::vector<int> DeleteDuplicates(std::vector<int>& numbers);

    /**
     * \brief Sort the array and remove duplicate elements.
     * \param numbers input array
     * \return sorted array with duplicates removed
     */
    std::vector<int> DeleteDuplicateElements(std::vector<int>& numbers);

    /**
     * \brief Remove all occurrences of a specific element from the array.
     * \param numbers input array
     * \param element value to remove
     * \return array without the specified element
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

    int size = static_cast<int>(numbers.size());

    // Replace duplicate elements with the next unique element
    int write_index = 1;
    for (int i = 1; i < size; ++i)
    {
        if (numbers[write_index - 1] != numbers[i])
        {
            numbers[write_index] = numbers[i];
            ++write_index;
        }
    }

    // Resize the vector to contain only the unique elements
    std::vector<int> result{numbers.begin(), numbers.begin() + write_index};

    return result;
}

// ----------------------------------------------------------------------------
inline std::vector<int> DeleteElement::DeleteDuplicateElements(std::vector<int>& numbers)
{
    if (numbers.empty())
    {
        return {};
    }

    // Sort the vector
    std::ranges::sort(numbers);
    // Remove duplicates and erase the redundant elements
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

    // Remove all occurrences of the specified element
    std::erase(numbers, element);

    return numbers;
}

#endif
