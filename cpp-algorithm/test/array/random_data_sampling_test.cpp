#include "random_data_sampling.h"

#include <gtest/gtest.h>
#include <iostream>

GTEST_TEST(RandomDataSamplingTest, OfflineRandomSampling)
{
    constexpr auto k = 3;
    auto arr = std::vector<int>{3, 7, 5, 11};
    const auto result = RandomDataSampling::OfflineRandomSampling(k, arr);

    std::stringstream stream;
    for (const auto& item : result)
    {
        stream << item << " ";
    }
    std::cout << stream.str() << std::endl;

    EXPECT_EQ(k, static_cast<int>(result.size()));
}

GTEST_TEST(RandomDataSamplingTest, ComputeRandomPermutation)
{
    constexpr auto k = 3;
    auto arr = std::vector<int>{3, 7, 5, 11};
    const auto result = RandomDataSampling::ComputeRandomPermutation(k);

    std::stringstream stream;
    for (const auto& item : result)
    {
        stream << item << " ";
    }
    std::cout << stream.str() << std::endl;

    EXPECT_EQ(k, static_cast<int>(result.size()));
}
