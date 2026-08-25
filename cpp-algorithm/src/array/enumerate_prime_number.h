#ifndef CPP_ALGORITHM_ENUMERATE_PRIME_NUMBER_H
#define CPP_ALGORITHM_ENUMERATE_PRIME_NUMBER_H

#include <deque>
#include <vector>

namespace EnumeratePrime
{
    /**
     * \brief Generates all prime numbers less than or equal to n.
     * \details Uses the Sieve of Eratosthenes to mark composite numbers.
     * \param n upper bound (inclusive)
     * \return prime numbers in ascending order
     */
    std::vector<int> GeneratePrimes(int n);
}

// ----------------------------------------------------------------------------
inline std::vector<int> EnumeratePrime::GeneratePrimes(const int n)
{
    std::vector<int> primes;
    std::deque<bool> is_prime(n + 1, true);

    // 0 and 1 are not prime numbers
    is_prime[0] = is_prime[1] = false;

    // mark every multiple of each prime as composite
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
