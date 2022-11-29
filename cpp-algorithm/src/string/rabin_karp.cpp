#include "rabin_karp.h"

auto RabinKarp::RabinKarpMatcher1(const std::string& text, const std::string& pattern) -> std::vector<int>
{
    auto result = std::vector<int>{};

    if (text.size() < pattern.size())
    {
        return result;
    }

    const auto pattern_hash = std::hash<std::string>{}(pattern);
    for (auto i = 0; i <= static_cast<int>(text.size()) - static_cast<int>(pattern.size()); ++i)
    {
        const auto next_hash = std::hash<std::string>{}(text.substr(i, pattern.size()));
        if (next_hash == pattern_hash
            && text.substr(i, pattern.size()) == pattern)
        {
            result.emplace_back(i);
        }
    }

    return result;
}

auto RabinKarp::RabinKarpMatcher2(const std::string& text, const std::string& pattern) -> std::vector<int>
{
    auto result = std::vector<int>{};

    if (text.size() < pattern.size())
    {
        return result;
    }

    constexpr auto base = 256;
    constexpr auto prime = 101;

    auto pattern_hash = 0;
    for (const auto ch : pattern)
    {
        pattern_hash = (base * pattern_hash + ch) % prime;
    }

    for (auto i = 0; i <= static_cast<int>(text.size()) - static_cast<int>(pattern.size()); ++i)
    {
        auto next_hash = 0;
        for (auto j = 0; j < static_cast<int>(pattern.size()); ++j)
        {
            next_hash = (base * next_hash + text[i + j]) % prime;
        }

        if (pattern_hash == next_hash)
        {
            auto is_match = true;
            for (auto j = 0; j < static_cast<int>(pattern.size()); ++j)
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
