#include "generate_random_number.h"

#include <random>

int ZeroOneRandom()
{
    std::default_random_engine generator((std::random_device())());
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}

int GenerateRandomNumber::GenerateUniformRandomNumber(const int lower_bound, const int upper_bound)
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
