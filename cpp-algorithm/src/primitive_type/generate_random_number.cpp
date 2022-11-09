#include "generate_random_number.h"

#include <random>

int ZeroOneRandom()
{
    std::default_random_engine generator((std::random_device())());
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}

int GenerateRandomNumber::GenerateUniformRandomNumber(const int lowerBound, const int upperBound)
{
    int result = 0;
    const int numberOfOutcomes = upperBound - lowerBound + 1;

    do
    {
        result = 0;
        for (int i = 0; (1 << i) < numberOfOutcomes; ++i)
        {
            result = (result << 1) | ZeroOneRandom();
        }
    } while (result >= numberOfOutcomes);

    return result + lowerBound;
}
