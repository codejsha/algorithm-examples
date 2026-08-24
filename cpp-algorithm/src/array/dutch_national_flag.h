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
    std::vector<Color> DutchFlagPartition1(
        int pivot_index,
        std::vector<Color>& arr);

    /**
     * \brief Dutch national flag problem.
     * \param pivot_index pivot index
     * \param arr input array
     * \return result array
     */
    std::vector<Color> DutchFlagPartition2(
        int pivot_index,
        std::vector<Color>& arr);

    /**
     * \brief Dutch national flag problem.
     * \param pivot_index pivot index
     * \param arr input array
     * \return result array
     */
    std::vector<Color> DutchFlagPartition3(
        int pivot_index,
        std::vector<Color>& arr);
}

// ----------------------------------------------------------------------------
inline std::vector<DutchFlag::Color> DutchFlag::DutchFlagPartition1(
    const int pivot_index,
    std::vector<Color>& arr)
{
    const Color pivot = arr[pivot_index];

    for (int i = 0; i < static_cast<Color>(arr.size()); ++i)
    {
        for (int j = i + 1; j < static_cast<Color>(arr.size()); ++j)
        {
            if (arr[j] < pivot)
            {
                std::swap(arr[i], arr[j]);
                break;
            }
        }
    }
    for (int i = static_cast<Color>(arr.size()) - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > pivot)
            {
                std::swap(arr[i], arr[j]);
                break;
            }
        }
    }

    return arr;
}

// ----------------------------------------------------------------------------
inline std::vector<DutchFlag::Color> DutchFlag::DutchFlagPartition2(
    const int pivot_index,
    std::vector<Color>& arr)
{
    const Color pivot = arr[pivot_index];

    int smaller = 0;
    for (int i = 0; i < static_cast<Color>(arr.size()); ++i)
    {
        if (arr[i] < pivot)
        {
            std::swap(arr[i], arr[smaller++]);
        }
    }

    int larger = static_cast<Color>(arr.size()) - 1;
    for (int i = static_cast<Color>(arr.size()) - 1; i >= 0; --i)
    {
        if (arr[i] > pivot)
        {
            std::swap(arr[i], arr[larger--]);
        }
    }

    return arr;
}

// ----------------------------------------------------------------------------
inline std::vector<DutchFlag::Color> DutchFlag::DutchFlagPartition3(
    const int pivot_index,
    std::vector<Color>& arr)
{
    const Color pivot = arr[pivot_index];

    int smaller = 0;
    int equal = 0;
    int larger = static_cast<Color>(arr.size());

    while (equal < larger)
    {
        if (arr[equal] < pivot)
        {
            std::swap(arr[smaller++], arr[equal++]);
        }
        else if (arr[equal] == pivot)
        {
            ++equal;
        }
        else
        {
            std::swap(arr[equal], arr[--larger]);
        }
    }

    return arr;
}

#endif
