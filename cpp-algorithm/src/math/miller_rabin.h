#ifndef CPP_ALGORITHM_MILLER_RABIN_H
#define CPP_ALGORITHM_MILLER_RABIN_H

namespace MillerRabin
{
    /// @brief Compute the modular exponentiation.
    /// @param base base
    /// @param exponent exponent
    /// @param mod modulus
    /// @return result: (base^exponent) % mod
    int ModularExponentiation(int base, int exponent, int mod);

    /// @brief Test whether the number is prime.
    /// Witness the Fermat's theorem: a^(p-1) = 1 (mod p)
    /// @param exponent exponent
    /// @param number number
    /// @return whether the number is prime
    bool Witness(int exponent, int number);

    /// @brief Miller-Rabin primality test.
    /// @param number input number
    /// @param repeats repeat times to increase the probability of correctness
    /// @return whether the number is prime or not
    bool MillerRabinPrimalityTest(int number, int repeats);
}

#endif
