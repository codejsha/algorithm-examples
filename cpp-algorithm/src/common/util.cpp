#include "util.h"
#include <iostream>
#include <random>
#include <vector>

void util::PrintSequence(std::vector<int>& seq)
{
    for (int element : seq)
    {
        std::printf("%d ", element);
    }
    std::cout << std::endl;
}

std::vector<int> util::GenerateSequence(int size, int min, int max)
{
    std::vector<int> seq;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(min, max);

    for (int count = 0; count < size; ++count)
    {
        seq.push_back(distribution(generator));
    }

    return seq;
}
