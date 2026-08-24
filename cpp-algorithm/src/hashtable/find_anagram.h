#ifndef CPP_ALGORITHM_FIND_ANAGRAM_H
#define CPP_ALGORITHM_FIND_ANAGRAM_H

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace FindAnagram
{
    /**
     * \brief Find the anagram mappings.
     * \param dictionary the dictionary of words
     * \return the anagram mappings
     */
    std::vector<std::vector<std::string>> FindAnagramMappings(
        const std::vector<std::string>& dictionary);
}

// ----------------------------------------------------------------------------
inline std::vector<std::vector<std::string>> FindAnagram::FindAnagramMappings(
    const std::vector<std::string>& dictionary)
{
    std::unordered_map<std::string, std::vector<std::string>> dictionary_map;
    for (const std::string& word : dictionary)
    {
        std::string sorted_word = word;
        std::ranges::sort(sorted_word);
        dictionary_map[sorted_word].emplace_back(word);
    }

    std::vector<std::vector<std::string>> anagram_mappings;
    for (const auto& [word, anagrams] : dictionary_map)
    {
        if (anagrams.size() > 1)
        {
            anagram_mappings.emplace_back(anagrams);
        }
    }
    return anagram_mappings;
}

#endif
