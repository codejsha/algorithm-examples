#ifndef CPP_ALGORITHM_RABIN_KARP_H
#define CPP_ALGORITHM_RABIN_KARP_H

#include <string>
#include <vector>

namespace RabinKarp
{
    /**
     * \brief Find all occurrences of a pattern in a text.
     * \param text input text
     * \param pattern patterns to find
     * \return starting indexes that match the pattern in the text
     */
    std::vector<int> RabinKarpMatcher1(
        const std::string& text,
        const std::string& pattern);

    /**
     * \brief Find all occurrences of a pattern in a text.
     * \param text input text
     * \param pattern patterns to find
     * \return starting indexes that match the pattern in the text
     */
    std::vector<int> RabinKarpMatcher2(
        const std::string& text,
        const std::string& pattern);
}

// ----------------------------------------------------------------------------
inline std::vector<int> RabinKarp::RabinKarpMatcher1(
    const std::string& text,
    const std::string& pattern)
{
    std::vector<int> result;

    if (text.size() < pattern.size())
    {
        return result;
    }

    const size_t pattern_hash = std::hash<std::string>{}(pattern);
    for (int i = 0; i <= static_cast<int>(text.size()) - static_cast<int>(pattern.size()); ++i)
    {
        const size_t next_hash = std::hash<std::string>{}(text.substr(i, pattern.size()));
        if (next_hash == pattern_hash && text.substr(i, pattern.size()) == pattern)
        {
            result.emplace_back(i);
        }
    }

    return result;
}

// ----------------------------------------------------------------------------
inline std::vector<int> RabinKarp::RabinKarpMatcher2(
    const std::string& text,
    const std::string& pattern)
{
    std::vector<int> result;

    if (text.size() < pattern.size())
    {
        return result;
    }

    constexpr int base = 256;
    constexpr int prime = 101;

    int pattern_hash = 0;
    for (const char ch : pattern)
    {
        pattern_hash = (base * pattern_hash + ch) % prime;
    }

    for (int i = 0; i <= static_cast<int>(text.size()) - static_cast<int>(pattern.size()); ++i)
    {
        int next_hash = 0;
        for (int j = 0; j < static_cast<int>(pattern.size()); ++j)
        {
            next_hash = (base * next_hash + text[i + j]) % prime;
        }

        if (pattern_hash == next_hash)
        {
            bool is_match = true;
            for (int j = 0; j < static_cast<int>(pattern.size()); ++j)
            {
                if (text[i + j] != pattern[j])
                {
                    is_match = false;
                    break;
                }
            }
            if (is_match)
            {
                result.emplace_back(i);
            }
        }
    }

    return result;
}

#endif
