#ifndef CPP_ALGORITHM_RANDOM_DATA_SAMPLING_H
#define CPP_ALGORITHM_RANDOM_DATA_SAMPLING_H

#include <vector>

namespace RandomDataSampling
{
    /// @brief Randomly select k elements from the array.
    /// @param k sample size
    /// @param arr input array
    /// @return result array
    std::vector<int> OfflineRandomSampling(int k, std::vector<int>& arr);

    // TODO: OnlineRandomSampling
    /// @brief Randomly select k elements from the array.
    /// @param begin begin iterator
    /// @param end end iterator
    /// @param k sample size
    /// @return result array
    std::vector<int> OnlineRandomSampling(
        const std::vector<int>::const_iterator& begin,
        const std::vector<int>::const_iterator& end,
        int k);

    /// @brief Compute permutation of the array generated by random sampling.
    /// @param n sample size
    /// @return result array
    std::vector<int> ComputeRandomPermutation(int n);
}

#endif