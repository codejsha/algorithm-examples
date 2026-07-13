#ifndef CPP_ALGORITHM_NAIVE_STRING_MATCH_H
#define CPP_ALGORITHM_NAIVE_STRING_MATCH_H

#include <string>
#include <vector>

namespace NaiveStringMatch
{
    /**
     * \brief Find all occurrences of a pattern in a text.
     * \param text input text
     * \param pattern find pattern
     * \return position of pattern in text
     */
    std::vector<int> NaiveStringMatcher(
        const std::string& text,
        const std::string& pattern);
}

// ----------------------------------------------------------------------------
inline std::vector<int> NaiveStringMatch::NaiveStringMatcher(
    const std::string& text,
    const std::string& pattern)
{
    std::vector<int> position;
    for (int i = 0; i < static_cast<int>(text.size()) - static_cast<int>(pattern.size()) + 1; ++i)
    {
        for (int j = 0; j < static_cast<int>(pattern.size()); ++j)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
            if (j == static_cast<int>(pattern.size()) - 1)
            {
                position.push_back(i);
            }
        }
    }
    return position;
}

#endif
