#ifndef CPP_ALGORITHM_H_INDEX_H
#define CPP_ALGORITHM_H_INDEX_H

#include <vector>

namespace HIndex
{
    /**
     * @brief Given an array of citations of a researcher, write a function to compute the researcher's h-index.
     * @param citations array of citations (each citation is a non-negative integer) of a researcher
     * @return h-index
     */
    auto HIndex(std::vector<int>& citations) -> int;
}

#endif
