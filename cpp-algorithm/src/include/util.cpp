#include "util.h"

#include <iostream>
#include <random>

void util::PrintSequence(const std::vector<int>& seq)
{
    for (const int element : seq)
    {
        std::printf("%d ", element);
    }
    std::cout << std::endl;
}

std::vector<int> util::GenerateSequence(const int size, const int min, const int max)
{
    std::vector<int> seq;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(min, max);
    
    seq.reserve(size);
    for (int count = 0; count < size; ++count)
    {
        seq.push_back(distribution(generator));
    }

    return seq;
}
