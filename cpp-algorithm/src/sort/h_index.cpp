#include "h_index.h"

#include <algorithm>
#include <ranges>

auto HIndex::HIndex1(std::vector<int>& citations) -> int
{
    // sort citations in descending order
    std::ranges::sort(citations, std::greater<>{});
    // std::sort(citations.begin(), citations.end(), std::greater<>());

    auto h_index = 0;
    for (auto i = 0; i < static_cast<int>(citations.size()); ++i)
    {
        // if current citation is greater than or equal to the number of papers
        if (citations[i] >= i + 1)
        {
            h_index = i + 1;
        }
        else
        {
            break;
        }
    }

    return h_index;
}

auto HIndex::HIndex2(std::vector<int>& citations) -> int
{
    // sort citations in descending order
    std::ranges::sort(citations, std::greater<>{});
    // std::sort(citations.begin(), citations.end(), std::greater<>());

    for (auto i = 0; i < static_cast<int>(citations.size()); ++i)
    {
        // if current citation is less than the number of papers
        if (citations[i] < i + 1)
        {
            return i;
        }
    }
    return 0;
}
