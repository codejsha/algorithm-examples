#ifndef CPP_ALGORITHM_ORDER_ELEMENT_H
#define CPP_ALGORITHM_ORDER_ELEMENT_H

#include <vector>

namespace OrderElement
{
    /// @brief Order even and odd numbers in the array.
    /// @param arr numbers
    void EvenOdd(std::vector<int>& arr);

    /// @brief Rearrange arrays to have a specific order.
    /// A[0] <= A[1] >= A[2] <= A[3] >= A[4] <= A[5] >= ...
    /// @param numbers input array
    /// @return ordered array
    std::vector<int> Rearrange(std::vector<int>& numbers);
}

#endif
