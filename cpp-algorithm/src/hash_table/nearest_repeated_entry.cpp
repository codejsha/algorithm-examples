#include "nearest_repeated_entry.h"

#include <unordered_map>

auto NearestRepeatedEntry::FindNearestRepeatedEntry(const std::vector<std::string>& paragraph) -> int
{
    std::unordered_map<std::string, int> last_occurrence;
    auto nearest_repeated_distance = std::numeric_limits<int>::max();

    // iterate over the array
    for (auto i = 0; i < static_cast<int>(paragraph.size()); ++i)
    {
        // if the current word has been seen before,
        // update the nearest repeated distance
        if (auto latest_equal_word = last_occurrence.find(paragraph[i]);
            latest_equal_word != last_occurrence.end())
        {
            nearest_repeated_distance =
                std::min(nearest_repeated_distance, i - latest_equal_word->second);
        }
        last_occurrence[paragraph[i]] = i;
    }

    // if no repeated words were found, return -1
    return nearest_repeated_distance != std::numeric_limits<int>::max()
               ? nearest_repeated_distance
               : -1;
}
