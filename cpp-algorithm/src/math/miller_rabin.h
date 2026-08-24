#ifndef CPP_ALGORITHM_MILLER_RABIN_H
#define CPP_ALGORITHM_MILLER_RABIN_H

#include <random>

namespace MillerRabin
{
    /**
     * \brief Compute the modular exponentiation.
     * \param base base
     * \param exponent exponent
     * \param mod modulus
     * \return result: (base^exponent) % mod
     */
    int ModularExponentiation(int base, int exponent, int mod);

    /**
     * \brief Test whether the number is prime.
     * Witness the Fermat's theorem: a^(p-1) = 1 (mod p)
     * \param exponent exponent
     * \param number number
     * \return whether the number is prime
     */
    bool Witness(int exponent, int number);

    /**
     * \brief Miller-Rabin primality test.
     * \param number input number
     * \param repeats repeat times to increase the probability of correctness
     * \return whether the number is prime or not
     */
    bool MillerRabinPrimalityTest(int number, int repeats);
}

// ----------------------------------------------------------------------------
inline int MillerRabin::ModularExponentiation(int base, int exponent, const int mod)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent /= 2;
        base = (base * base) % mod;
    }
    return result;
}

// ----------------------------------------------------------------------------
inline bool MillerRabin::Witness(int exponent, const int number)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution distribution(2, number - 1);
    const int random = distribution(generator);
    int x = ModularExponentiation(random, exponent, number);

    if (x == 1 || x == number - 1)
    {
        return true;
    }

    while (exponent != number - 1)
    {
        x = (x * x) % number;
        exponent *= 2;

        if (x == 1)
        {
            return false;
        }
        if (x == number - 1)
        {
            return true;
        }
    }

    return false;
}

// ----------------------------------------------------------------------------
inline bool MillerRabin::MillerRabinPrimalityTest(const int number, const int repeats)
{
    if (number < 2)
    {
        return false;
    }
    if (number == 2)
    {
        return true;
    }
    if (number % 2 == 0)
    {
        return false;
    }

    int d = number - 1;
    while (d % 2 == 0)
    {
        d /= 2;
    }

    for (int i = 0; i < repeats; ++i)
    {
        if (!Witness(d, number))
        {
            return false;
        }
    }

    return true;
}

#endif
