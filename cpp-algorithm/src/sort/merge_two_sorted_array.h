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
    void MergeTwoSortedArray(std::vector<int>& seq1, int m, const std::vector<int>& seq2, int n);
}

#endif
