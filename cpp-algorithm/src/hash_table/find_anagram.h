#ifndef CPP_ALGORITHM_FIND_ANAGRAM_H
#define CPP_ALGORITHM_FIND_ANAGRAM_H

#include <string>
#include <vector>

namespace FindAnagram
{
    /// @brief Find the anagram mappings.
    /// @param dictionary the dictionary of words
    /// @return the anagram mappings
    auto FindAnagramMappings(const std::vector<std::string>& dictionary) -> std::vector<std::vector<std::string>>;
}

#endif
