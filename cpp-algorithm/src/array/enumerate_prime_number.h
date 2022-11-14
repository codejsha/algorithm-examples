#ifndef CPP_ALGORITHM_ENUMERATE_PRIME_H
#define CPP_ALGORITHM_ENUMERATE_PRIME_H

#include <vector>

namespace EnumeratePrime
{
    /// @brief Enumerate prime numbers in the range.
    /// @param n upper bound
    /// @return prime numbers
    std::vector<int> GeneratePrimes(int n);
}

#endif
