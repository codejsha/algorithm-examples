#ifndef CPP_ALGORITHM_RABIN_KARP_H
#define CPP_ALGORITHM_RABIN_KARP_H

#include <string>
#include <vector>

namespace RabinKarp
{
    /// @brief Find all occurrences of a pattern in a text.
    /// @param text input text
    /// @param pattern pattens to find
    /// @return starting indexes that match the pattern in the text
    auto RabinKarpMatcher1(const std::string& text, const std::string& pattern) -> std::vector<int>;

    /// @brief Find all occurrences of a pattern in a text.
    /// @param text input text
    /// @param pattern pattens to find
    /// @return starting indexes that match the pattern in the text
    auto RabinKarpMatcher2(const std::string& text, const std::string& pattern) -> std::vector<int>;
}

#endif
