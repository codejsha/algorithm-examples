#ifndef CPP_ALGORITHM_ENUMERATE_PRIME_NUMBER_H
#define CPP_ALGORITHM_ENUMERATE_PRIME_NUMBER_H

#include <vector>

namespace EnumeratePrime
{
    /// @brief Enumerate prime numbers in the range.
    /// @param n upper bound
    /// @return prime numbers
    auto GeneratePrimes(int n) -> std::vector<int>;
}

#endif
