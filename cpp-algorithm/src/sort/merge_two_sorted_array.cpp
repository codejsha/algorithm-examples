#include "merge_two_sorted_array.h"

void MergeTwoSortedArray::MergeTwoSortedArray(std::vector<int>& seq1, const int m, const std::vector<int>& seq2,
                                              const int n)
{
    auto i = m - 1;
    auto j = n - 1;
    auto k = m + n - 1;

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
