#ifndef CPP_ALGORITHM_NAIVE_STRING_MATCH_H
#define CPP_ALGORITHM_NAIVE_STRING_MATCH_H

#include <string>
#include <vector>

namespace NaiveStringMatch
{
    /// @brief Find all occurrences of a pattern in a text.
    /// @param text input text
    /// @param pattern find pattern
    /// @return position of pattern in text
    std::vector<int> NaiveStringMatcher(const std::string& text, const std::string& pattern);
}

#endif
