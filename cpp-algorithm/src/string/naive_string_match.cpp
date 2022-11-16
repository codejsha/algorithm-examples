#include "naive_string_match.h"

std::vector<int> NaiveStringMatch::NaiveStringMatcher(const std::string& text, const std::string& pattern)
{
    auto position = std::vector<int>{};
    for (auto i = 0; i < static_cast<int>(text.size()) - static_cast<int>(pattern.size()) + 1; ++i)
    {
        for (auto j = 0; j < static_cast<int>(pattern.size()); ++j)
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
