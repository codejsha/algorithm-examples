#include "miller_rabin.h"

#include <random>

auto MillerRabin::ModularExponentiation(int base, int exponent, const int mod) -> int
{
    auto result = 1;
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

auto MillerRabin::Witness(int exponent, const int number) -> bool
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(2, number - 1);
    const auto random = distribution(generator);
    auto x = ModularExponentiation(random, exponent, number);

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

auto MillerRabin::MillerRabinPrimalityTest(const int number, const int repeats) -> bool
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

    auto d = number - 1;
    while (d % 2 == 0)
    {
        d /= 2;
    }

    for (auto i = 0; i < repeats; ++i)
    {
        if (!Witness(d, number))
        {
            return false;
        }
    }

    return true;
}
