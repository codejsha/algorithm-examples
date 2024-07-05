#include "find_anagram.h"

#include <algorithm>
#include <unordered_map>

auto FindAnagram::FindAnagramMappings(const std::vector<std::string>& dictionary)
    -> std::vector<std::vector<std::string>>
{
    std::unordered_map<std::string, std::vector<std::string>> dictionary_map;
    for (const std::string& word : dictionary)
    {
        auto sorted_word = word;
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
