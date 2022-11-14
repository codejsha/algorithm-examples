#ifndef CPP_ALGORITHM_GENERATE_RANDOM_NUMBER_H
#define CPP_ALGORITHM_GENERATE_RANDOM_NUMBER_H

namespace GenerateRandomNumber
{
    /// @brief Generate a random number in a range with equal probability.
    /// @param lower_bound lower bound
    /// @param upper_bound upper bound
    /// @return result number
    int GenerateUniformRandomNumber(int lower_bound, int upper_bound);
}

#endif
