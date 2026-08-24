#ifndef CPP_ALGORITHM_NEAREST_REPEATED_ENTRY_H
#define CPP_ALGORITHM_NEAREST_REPEATED_ENTRY_H

#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

namespace NearestRepeatedEntry
{
    /**
     * \brief Find the nearest repeated entry in an array of strings.
     * \details Given an array of strings, find the distance between the closest pair of equal entries.
     * \param paragraph an array of strings
     * \return the distance between the closest pair of equal entries
     */
    int FindNearestRepeatedEntry(
        const std::vector<std::string>& paragraph);
}

// ----------------------------------------------------------------------------
inline int NearestRepeatedEntry::FindNearestRepeatedEntry(
    const std::vector<std::string>& paragraph)
{
    std::unordered_map<std::string, int> last_occurrence;
    int nearest_repeated_distance = std::numeric_limits<int>::max();

    // iterate over the array
    for (int i = 0; i < static_cast<int>(paragraph.size()); ++i)
    {
        // if the current word has been seen before,
        // update the nearest repeated distance
        if (auto latest_equal_word = last_occurrence.find(paragraph[i]); latest_equal_word != last_occurrence.end())
        {
            nearest_repeated_distance = std::min(nearest_repeated_distance, i - latest_equal_word->second);
        }
        last_occurrence[paragraph[i]] = i;
    }

    // if no repeated words were found, return -1
    return nearest_repeated_distance != std::numeric_limits<int>::max() ? nearest_repeated_distance : -1;
}

#endif
