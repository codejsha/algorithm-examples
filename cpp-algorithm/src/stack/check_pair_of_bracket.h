#ifndef CPP_ALGORITHM_CHECK_PAIR_OF_BRACKET_H
#define CPP_ALGORITHM_CHECK_PAIR_OF_BRACKET_H

#include <string>

namespace PairOfBracket
{
    /// @brief Checks if the input string contains bracket pairs and is well-formed.
    /// @param input The input string.
    /// @return True if the input string contains a pair of bracket, false otherwise.
    auto CheckPairOfBracket(const std::string& input) -> bool;
}
#endif
