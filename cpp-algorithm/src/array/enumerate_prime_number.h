#ifndef CPP_ALGORITHM_ENUMERATE_PRIME_NUMBER_H
#define CPP_ALGORITHM_ENUMERATE_PRIME_NUMBER_H

#include <deque>
#include <vector>

namespace EnumeratePrime
{
    /**
     * \brief Enumerate prime numbers in the range.
     * \param n upper bound
     * \return prime numbers
     */
    std::vector<int> GeneratePrimes(int n);
}

// ----------------------------------------------------------------------------
inline std::vector<int> EnumeratePrime::GeneratePrimes(const int n)
{
    std::vector<int> primes;
    std::deque<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p <= n; ++p)
    {
        if (is_prime[p])
        {
            primes.push_back(p);
            for (int i = p * 2; i <= n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    return primes;
}

#endif
