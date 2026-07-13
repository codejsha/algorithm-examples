#ifndef CPP_ALGORITHM_ANONYMOUS_LETTER_H
#define CPP_ALGORITHM_ANONYMOUS_LETTER_H

#include <sstream>
#include <string>
#include <unordered_map>

namespace AnonymousLetter
{
    /**
     * \brief Check if a letter can be written using the characters in a magazine.
     * \details When given anonymous letter text and magazine text,
     * determine if it is possible to write the anonymous letter using the magazine.
     * \param letter a letter
     * \param magazine a magazine
     * \return true if the letter can be written using the characters in the magazine, false otherwise
     **/
    bool IsLetterConstructibleFromMagazine(
        const std::string& letter,
        const std::string& magazine);

    /**
     * \brief Check if a letter can be written using the words in a magazine.
     * \details When given anonymous letter text and magazine text,
     * determine if it is possible to write the anonymous letter using the words in the magazine.
     * \param letter a letter
     * \param magazine a magazine
     * \return true if the letter can be written using the words in the magazine, false otherwise
     **/
    bool IsWordConstructibleFromMagazine(
        const std::string& letter,
        const std::string& magazine);
}

// ----------------------------------------------------------------------------
inline bool AnonymousLetter::IsLetterConstructibleFromMagazine(
    const std::string& letter,
    const std::string& magazine)
{
    // count the number of times each character appears in the letter
    std::unordered_map<char, int> char_frequency_for_letter;
    for (const char& ch : letter)
    {
        ++char_frequency_for_letter[ch];
    }

    // check if the characters in magazine can cover characters in letter
    for (const char& ch : magazine)
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

// ----------------------------------------------------------------------------
/**
 * \brief Split a string into words.
 * \param str a string
 * \return a map of words and their frequencies
 */
inline std::unordered_map<std::string, int> SplitIntoWords(const std::string& str)
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

// ----------------------------------------------------------------------------
inline bool AnonymousLetter::IsWordConstructibleFromMagazine(
    const std::string& letter,
    const std::string& magazine)
{
    // count the number of times each word appears in the letter
    std::unordered_map<std::string, int> word_frequency_for_letter = SplitIntoWords(letter);

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

#endif
