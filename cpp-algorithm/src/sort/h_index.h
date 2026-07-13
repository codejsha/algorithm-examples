#ifndef CPP_ALGORITHM_H_INDEX_H
#define CPP_ALGORITHM_H_INDEX_H

#include <algorithm>
#include <ranges>
#include <vector>

namespace HIndex
{
    /**
     * \brief Given an array of citations of a researcher, write a function to compute the researcher's h-index.
     * \param citations array of citations (each citation is a non-negative integer) of a researcher
     * \return h-index
     */
    int HIndex1(std::vector<int>& citations);

    /**
     * \brief Given an array of citations of a researcher, write a function to compute the researcher's h-index.
     * \param citations array of citations (each citation is a non-negative integer) of a researcher
     * \return h-index
     */
    int HIndex2(std::vector<int>& citations);
}

// ----------------------------------------------------------------------------
inline int HIndex::HIndex1(std::vector<int>& citations)
{
    // sort citations in descending order
    std::ranges::sort(citations, std::greater<>{});
    // std::sort(citations.begin(), citations.end(), std::greater<>());

    int h_index = 0;
    for (int i = 0; i < static_cast<int>(citations.size()); ++i)
    {
        // if current citation is greater than or equal to the number of papers
        if (citations[i] >= i + 1)
        {
            h_index = i + 1;
        }
        else
        {
            break;
        }
    }

    return h_index;
}

// ----------------------------------------------------------------------------
inline int HIndex::HIndex2(std::vector<int>& citations)
{
    // sort citations in descending order
    std::ranges::sort(citations, std::greater<>{});
    // std::sort(citations.begin(), citations.end(), std::greater<>());

    for (int i = 0; i < static_cast<int>(citations.size()); ++i)
    {
        // if current citation is less than the number of papers
        if (citations[i] < i + 1)
        {
            return i;
        }
    }
    return 0;
}

#endif
