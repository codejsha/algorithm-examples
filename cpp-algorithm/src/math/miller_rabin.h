#ifndef CPP_ALGORITHM_MILLER_RABIN_H
#define CPP_ALGORITHM_MILLER_RABIN_H

namespace MillerRabin
{
    /// @brief Compute the modular exponentiation.
    /// @param base base
    /// @param exponent exponent
    /// @param mod modulus
    /// @return result: (base^exponent) % mod
    auto ModularExponentiation(int base, int exponent, int mod) -> int;

    /// @brief Test whether the number is prime.
    /// Witness the Fermat's theorem: a^(p-1) = 1 (mod p)
    /// @param exponent exponent
    /// @param number number
    /// @return whether the number is prime
    auto Witness(int exponent, int number) -> bool;

    /// @brief Miller-Rabin primality test.
    /// @param number input number
    /// @param repeats repeat times to increase the probability of correctness
    /// @return whether the number is prime or not
    auto MillerRabinPrimalityTest(int number, int repeats) -> bool;
}

#endif
