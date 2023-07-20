#ifndef CPP_ALGORITHM_DUTCH_NATIONAL_FLAG_H
#define CPP_ALGORITHM_DUTCH_NATIONAL_FLAG_H

#include <vector>

namespace DutchFlag
{
    /**
     * \brief Color enum
     */
    enum Color
    {
        Red,
        White,
        Blue
    };

    /**
     * \brief Dutch national flag problem.
     * \param pivot_index pivot index
     * \param arr input array
     * \return result array
     */
    auto DutchFlagPartition1(int pivot_index, std::vector<Color>& arr) -> std::vector<Color>;

    /**
     * \brief Dutch national flag problem.
     * \param pivot_index pivot index
     * \param arr input array
     * \return result array
     */
    auto DutchFlagPartition2(int pivot_index, std::vector<Color>& arr) -> std::vector<Color>;

    /**
     * \brief Dutch national flag problem.
     * \param pivot_index pivot index
     * \param arr input array
     * \return result array
     */
    auto DutchFlagPartition3(int pivot_index, std::vector<Color>& arr) -> std::vector<Color>;
}

#endif
