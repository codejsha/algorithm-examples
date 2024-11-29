#include "smallest_subarray.h"

#include <limits>
#include <unordered_map>

auto SmallestSubarray::FindSmallestSubarrayCoveringSubset(const std::vector<std::string>& paragraph,
                                                          const std::vector<std::string>& keywords)
    -> std::tuple<int, int>
{
    // keep track of the number of keywords that have been covered
    std::unordered_map<std::string, int> keywords_to_cover;
    for (const std::string& keyword : keywords)
    {
        ++keywords_to_cover[keyword];
    }

    std::tuple<int, int> result = std::make_tuple(-1, -1);
    size_t remaining_to_cover = keywords.size();

    for (int left_index = 0, right_index = 0; right_index < static_cast<int>(paragraph.size()); ++right_index)
    {
        // decrement the number of keywords that need to be covered
        const std::string& right_word = paragraph[right_index];
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
                || right_index - left_index < std::get<1>(result) - std::get<0>(result))
            {
                result = std::tuple{left_index, right_index};
            }

            // increment the number of keywords that need to be covered
            const std::string& left_word = paragraph[left_index];
            if (const auto it = keywords_to_cover.find(left_word);
                it != keywords_to_cover.end())
            {
                ++it->second;
                if (it->second > 0)
                {
                    ++remaining_to_cover;
                }
            }

            ++left_index;
        }
    }

    return result;
}

auto SmallestSubarray::FindSmallestSubarraySequentiallyCoveringSubset(const std::vector<std::string>& paragraph,
                                                                      const std::vector<std::string>& keywords)
    -> std::tuple<int, int>
{
    // map each keyword to its index in the keywords vector
    std::unordered_map<std::string, int> keywords_to_index;
    for (int i = 0; i < static_cast<int>(keywords.size()); ++i)
    {
        keywords_to_index[keywords[i]] = i;
    }

    std::vector<int> last_occurrence = std::vector(keywords.size(), -1);
    std::vector<int> shortest_subarray_length = std::vector(keywords.size(), std::numeric_limits<int>::max());

    int shortest_distance = std::numeric_limits<int>::max();
    std::tuple<int, int> result = std::make_tuple(-1, -1);

    for (int i = 0; i < static_cast<int>(paragraph.size()); ++i)
    {
        if (const std::string& word = paragraph[i];
            keywords_to_index.contains(word))
        {
            const int keyword_index = keywords_to_index.find(word)->second;

            // if keyword is the first one in the keywords vector
            if (keyword_index == 0)
            {
                shortest_subarray_length[keyword_index] = 1;
            }
            // if the shortest subarray length of the previous keyword is not infinite
            else if (shortest_subarray_length[keyword_index - 1] != std::numeric_limits<int>::max())
            {
                const int distance_to_previous_keyword = i - last_occurrence[keyword_index - 1];
                shortest_subarray_length[keyword_index] =
                    distance_to_previous_keyword + shortest_subarray_length[keyword_index - 1];
            }
            last_occurrence[keyword_index] = i;

            // if the current keyword is the last one
            // and its shortest subarray length is smaller than the current shortest distance
            if (keyword_index == static_cast<int>(keywords.size()) - 1
                && shortest_subarray_length.back() < shortest_distance)
            {
                shortest_distance = shortest_subarray_length.back();
                result = std::tuple{i - shortest_distance + 1, i};
            }
        }
    }

    return result;
}
