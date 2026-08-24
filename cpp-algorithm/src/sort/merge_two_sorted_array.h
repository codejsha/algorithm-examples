#ifndef CPP_ALGORITHM_MERGE_TWO_SORTED_ARRAY_H
#define CPP_ALGORITHM_MERGE_TWO_SORTED_ARRAY_H

#include <vector>

namespace MergeTwoSortedArray
{
    /**
     * \brief Merge two sorted array.
     * The first array has enough space to hold the second array.
     * Merge the second array into the first array.
     * \param seq1 first sorted array
     * \param m number of elements in the first array
     * \param seq2 second sorted array
     * \param n number of elements in the second array
     */
    void MergeTwoSortedArray(
        std::vector<int>& seq1,
        int m,
        const std::vector<int>& seq2,
        int n);
}

// ----------------------------------------------------------------------------
inline void MergeTwoSortedArray::MergeTwoSortedArray(
    std::vector<int>& seq1,
    const int m,
    const std::vector<int>& seq2,
    const int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (seq1[i] > seq2[j])
        {
            seq1[k--] = seq1[i--];
        }
        else
        {
            seq1[k--] = seq2[j--];
        }
    }

    while (j >= 0)
    {
        seq1[k--] = seq2[j--];
    }
}

#endif
