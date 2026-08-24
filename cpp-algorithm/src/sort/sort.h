#ifndef CPP_ALGORITHM_SORT_H
#define CPP_ALGORITHM_SORT_H

#include <vector>

namespace Sort
{
    /**
     * \brief Selection sort algorithm.
     * \param seq sequence of elements
     * \return sorted sequence
     */
    std::vector<int> SelectionSort(std::vector<int>& seq);

    /**
     * \brief Insertion sort algorithm.
     * \param seq sequence of elements
     * \return sorted sequence
     */
    std::vector<int> InsertionSort(std::vector<int>& seq);
}

// ----------------------------------------------------------------------------
inline std::vector<int> Sort::InsertionSort(std::vector<int>& seq)
{
    const int size = static_cast<int>(seq.size());

    for (int index = 1; index < size; ++index)
    {
        int key = index;
        while ((key > 0) && (seq[key] < seq[key - 1]))
        {
            std::swap(seq[key], seq[key - 1]);
            key--;
        }
    }
    return seq;
}

// ----------------------------------------------------------------------------
inline std::vector<int> Sort::SelectionSort(std::vector<int>& seq)
{
    for (int prev = 0; prev < static_cast<int>(seq.size()); ++prev)
    {
        int min_index = prev;
        for (int next = prev + 1; next < static_cast<int>(seq.size()); ++next)
        {
            if (seq[min_index] > seq[next])
            {
                min_index = next;
            }
        }
        std::swap(seq[prev], seq[min_index]);
    }
    return seq;
}

#endif
