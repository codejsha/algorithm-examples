#include "anonymous_letter.h"

#include <sstream>
#include <unordered_map>

auto AnonymousLetter::IsLetterConstructibleFromMagazine(const std::string& letter, const std::string& magazine) -> bool
{
    // count the number of times each character appears in the letter
    std::unordered_map<char, int> char_frequency_for_letter;
    for (const auto& ch : letter)
    {
        ++char_frequency_for_letter[ch];
    }
    // check if the characters in magazine can cover characters in letter
    for (const auto& ch : magazine)
    {
        const auto it = char_frequency_for_letter.find(ch);
        if (it != char_frequency_for_letter.end())
        {
            --it->second;
            if (it->second == 0)
            {
                char_frequency_for_letter.erase(it);
                // all characters for letter are matched
                if (char_frequency_for_letter.empty())
                {
                    break;
                }
            }
        }
    }
    return char_frequency_for_letter.empty();
}

/// @brief Split a string into words.
/// @param str a string
/// @return a map of words and their frequencies
auto SplitIntoWords(const std::string& str) -> std::unordered_map<std::string, int>
{
    std::unordered_map<std::string, int> word_frequency;
    std::istringstream iss(str);
    std::string word;
    while (iss >> word)
    {
        ++word_frequency[word];
    }
    return word_frequency;
}

auto AnonymousLetter::IsWordConstructibleFromMagazine(const std::string& letter, const std::string& magazine) -> bool
{
    // count the number of times each word appears in the letter
    auto word_frequency_for_letter = SplitIntoWords(letter);
    // check if the words in magazine can cover words in letter
    for (const auto& [fst, snd] : SplitIntoWords(magazine))
    {
        const auto it = word_frequency_for_letter.find(fst);
        if (it != word_frequency_for_letter.end())
        {
            --it->second;
            if (it->second == 0)
            {
                word_frequency_for_letter.erase(it);
                // all words for letter are matched
                if (word_frequency_for_letter.empty())
                {
                    break;
                }
            }
        }
    }
    return word_frequency_for_letter.empty();
}
