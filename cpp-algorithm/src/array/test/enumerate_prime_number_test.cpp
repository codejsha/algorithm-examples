#include "enumerate_prime_number.h"

#include <gtest/gtest.h>

GTEST_TEST(EnumeratePrime, GeneratePrimes)
{
    const auto expected = std::vector<int>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    const auto result = EnumeratePrime::GeneratePrimes(100);
    EXPECT_EQ(expected, result);
}
