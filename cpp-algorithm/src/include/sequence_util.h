#ifndef CPP_ALGORITHM_SEQUENCE_UTIL_H
#define CPP_ALGORITHM_SEQUENCE_UTIL_H

#include <iostream>
#include <random>
#include <vector>

namespace Util
{
    /**
     * \brief Print sequence to standard output.
     * \param seq input sequence
     */
    void PrintSequence(const std::vector<int>& seq);

    /**
     * \brief Generate sequence.
     * \param size sequence size
     * \param min minimum value bound
     * \param max maximum value bound
     * \return result sequence
     */
    std::vector<int> GenerateSequence(int size, int min, int max);
}

// ----------------------------------------------------------------------------
inline void Util::PrintSequence(const std::vector<int>& seq)
{
    for (const int element : seq)
    {
        std::printf("%d ", element);
    }
    std::cout << std::endl;
}

// ----------------------------------------------------------------------------
inline std::vector<int> Util::GenerateSequence(const int size, const int min, const int max)
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

#endif
