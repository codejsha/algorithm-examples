#ifndef CPP_ALGORITHM_SEQUENCE_UTIL_H
#define CPP_ALGORITHM_SEQUENCE_UTIL_H

#include <vector>

namespace Util
{
    /// @brief Print sequence to standard output.
    /// @param seq input sequence
    void PrintSequence(const std::vector<int>& seq);

    /// @brief Generate sequence.
    /// @param size sequence size
    /// @param min minimum value bound
    /// @param max maximum value bound
    /// @return result sequence
    auto GenerateSequence(int size, int min, int max) -> std::vector<int>;
}

#endif
