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

auto RandomDataSampling::OnlineRandomSampling(std::vector<int>::const_iterator begin,
                                              const std::vector<int>::const_iterator end,
                                              const int k)
    -> std::vector<int>
{
    std::vector<int> running_sample;
    // save the first k elements
    for (int i = 0; i < k; ++i)
    {
        running_sample.emplace_back(*begin++);
    }

    std::default_random_engine seed((std::random_device())());
    int num_seen_so_far = k;
    while (begin != end)
    {
        int x = *begin++;
        ++num_seen_so_far;

        // generate a random number in [0, num_seen_so_far].
        // if the generated number exists in [0, k), replace the element with x.
        const int idx_to_replace = std::uniform_int_distribution<int>{0, num_seen_so_far - 1}(seed);
        if (idx_to_replace < k)
        {
            running_sample[idx_to_replace] = x;
        }
    }

    return running_sample;
}

auto RandomDataSampling::ComputeRandomPermutation(const int n) -> std::vector<int>
{
    auto permutation = std::vector<int>(n);
    std::iota(permutation.begin(), permutation.end(), 0);
    return OfflineRandomSampling(n, permutation);
}
