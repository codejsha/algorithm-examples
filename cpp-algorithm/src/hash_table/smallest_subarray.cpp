#include "smallest_subarray.h"

#include <unordered_map>

auto SmallestSubarray::FindSmallestSubarrayCoveringSet(
    const std::vector<std::string>& paragraph,
    const std::unordered_set<std::string>& keywords)
    -> std::tuple<int, int>
{
    // keep track of the number of keywords that have been covered
    std::unordered_map<std::string, int> keywords_to_cover;
    for (const auto& keyword : keywords)
    {
        ++keywords_to_cover[keyword];
    }

    auto result = std::make_tuple(-1, -1);
    auto remaining_to_cover = keywords.size();
    
    for (auto left = 0, right = 0; right < static_cast<int>(paragraph.size()); ++right)
    {
        // decrement the number of keywords that need to be covered
        const auto& right_word = paragraph[right];
        if (const auto it = keywords_to_cover.find(right_word);
            it != keywords_to_cover.end())
        {
            --it->second;
            if (it->second >= 0)
            {
                --remaining_to_cover;
            }
        }

        // advance left pointer until keywords_to_cover does not contain all keywords
        while (remaining_to_cover == 0)
        {
            // if result is not set yet
            // or the current subarray is smaller than the current result
            if (std::get<0>(result) == -1
                || right - left < std::get<1>(result) - std::get<0>(result))
            {
                result = {left, right};
            }

            // increment the number of keywords that need to be covered
            const auto& left_word = paragraph[left];
            if (const auto it = keywords_to_cover.find(left_word);
                it != keywords_to_cover.end())
            {
                ++it->second;
                if (it->second > 0)
                {
                    ++remaining_to_cover;
                }
            }

            ++left;
        }
    }
    return result;
}
