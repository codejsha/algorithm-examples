#ifndef CPP_ALGORITHM_GENERATE_RANDOM_NUMBER_H
#define CPP_ALGORITHM_GENERATE_RANDOM_NUMBER_H

#include <random>

namespace GenerateRandomNumber
{
    /**
     * \brief Generate a random number in a range with equal probability.
     * \param lower_bound lower bound
     * \param upper_bound upper bound
     * \return result number
     */
    int GenerateUniformRandomNumber(
        int lower_bound,
        int upper_bound);
}

// ----------------------------------------------------------------------------
inline int ZeroOneRandom()
{
    std::default_random_engine generator((std::random_device())());
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}

// ----------------------------------------------------------------------------
inline int GenerateRandomNumber::GenerateUniformRandomNumber(
    const int lower_bound,
    const int upper_bound)
{
    int result = 0;
    const int number_of_outcomes = upper_bound - lower_bound + 1;

    do
    {
        result = 0;
        for (int i = 0; (1 << i) < number_of_outcomes; ++i)
        {
            result = (result << 1) | ZeroOneRandom();
        }
    } while (result >= number_of_outcomes);

    return result + lower_bound;
}

#endif
