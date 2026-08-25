#ifndef CPP_ALGORITHM_ORDER_ELEMENT_H
#define CPP_ALGORITHM_ORDER_ELEMENT_H

#include <vector>

namespace OrderElement
{
    /**
     * \brief Partitions the array so that even numbers appear before odd numbers.
     * \details Uses two pointers moving toward each other: evens grow from the
     * front and odds grow from the back, swapping elements as needed.
     * \param arr numbers to partition (modified in place)
     */
    void EvenOdd(
        std::vector<int>& arr);

    /**
     * \brief Rearranges the array into an alternating (zigzag) order.
     * \details The result satisfies A[0] <= A[1] >= A[2] <= A[3] >= A[4] <= ...
     * by swapping adjacent elements whenever they violate the desired relation.
     * \param numbers input array (modified in place)
     * \return rearranged array
     */
    std::vector<int> Rearrange(
        std::vector<int>& numbers);
}

// ----------------------------------------------------------------------------
inline void OrderElement::EvenOdd(
    std::vector<int>& arr)
{
    // even elements are placed in [0, next_even),
    // odd elements are placed in (next_odd, size - 1]
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
            // move the odd element to the back
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
        // even index: require numbers[i - 1] >= numbers[i],
        // odd index: require numbers[i - 1] <= numbers[i]
        if ((!(i % 2) && numbers[i - 1] < numbers[i]) || ((i % 2) && numbers[i - 1] > numbers[i]))
        {
            std::swap(numbers[i - 1], numbers[i]);
        }
    }
    return numbers;
}

#endif
