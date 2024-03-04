#include "random_data_sampling.h"

#include <numeric>
#include <random>

auto RandomDataSampling::OfflineRandomSampling(const int k, std::vector<int>& arr) -> std::vector<int>
{
    std::default_random_engine seed((std::random_device())());
    for (int i = 0; i < k; ++i)
    {
        std::uniform_int_distribution<int> dist(i, static_cast<int>(arr.size()) - 1);
        std::swap(arr[i], arr[dist(seed)]);
    }
    return std::vector<int>{arr.begin(), arr.begin() + k};
}

auto RandomDataSampling::ComputeRandomPermutation(const int n) -> std::vector<int>
{
    auto permutation = std::vector<int>(n);
    std::iota(permutation.begin(), permutation.end(), 0);
    return OfflineRandomSampling(n, permutation);
}
