#ifndef CPP_ALGORITHM_ORDER_ELEMENT_H
#define CPP_ALGORITHM_ORDER_ELEMENT_H

#include <vector>

namespace OrderElement
{
    /**
     * \brief Partition the array so that even numbers appear before odd numbers.
     * \details Two pointers sweep from both ends: evens stay at the front and
     * odds are swapped to the back. The relative order of elements is not
     * preserved. Time complexity: O(n), Space complexity: O(1)
     * Example: [1, 2, 3, 4] -> [4, 2, 3, 1]
     * \param arr input array (partitioned in-place)
     */
    void EvenOdd(
        std::vector<int>& arr);

    /**
     * \brief Rearrange the array into an alternating order such that
     * A[0] <= A[1] >= A[2] <= A[3] >= A[4] <= A[5] >= ...
     * \details A single pass swaps adjacent elements whenever they violate the
     * relation required at that position; a swap cannot break the relation
     * already established at the previous position.
     * Time complexity: O(n), Space complexity: O(1)
     * Example: [3, 1, 4, 1, 5] -> [1, 4, 1, 5, 3]
     * \param numbers input array (rearranged in-place)
     * \return rearranged array
     */
    std::vector<int> Rearrange(
        std::vector<int>& numbers);
}

// ----------------------------------------------------------------------------
inline void OrderElement::EvenOdd(
    std::vector<int>& arr)
{
    int next_even = 0;
    int next_odd = static_cast<int>(arr.size()) - 1;

    while (next_even < next_odd)
    {
        if (arr[next_even] % 2 == 0)
        {
            ++next_even;
        }
        else
        {
            std::swap(arr[next_even], arr[next_odd]);
            --next_odd;
        }
    }
}

// ----------------------------------------------------------------------------
inline std::vector<int> OrderElement::Rearrange(
    std::vector<int>& numbers)
{
    for (int i = 1; i < static_cast<int>(std::size(numbers)); ++i)
    {
        // Swap when the pair violates the required relation at this position:
        // even index i must not be greater than its predecessor, odd index i must not be smaller.
        if ((!(i % 2) && numbers[i - 1] < numbers[i]) || ((i % 2) && numbers[i - 1] > numbers[i]))
        {
            std::swap(numbers[i - 1], numbers[i]);
        }
    }
    return numbers;
}

#endif
