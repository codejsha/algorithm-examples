#ifndef CPP_ALGORITHM_ANONYMOUS_LETTER_H
#define CPP_ALGORITHM_ANONYMOUS_LETTER_H

#include <string>

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
    auto IsLetterConstructibleFromMagazine(const std::string& letter, const std::string& magazine) -> bool;

    /**
     * \brief Check if a letter can be written using the words in a magazine.
     * \details When given anonymous letter text and magazine text,
     * determine if it is possible to write the anonymous letter using the words in the magazine.
     * \param letter a letter
     * \param magazine a magazine
     * \return true if the letter can be written using the words in the magazine, false otherwise
     **/
    auto IsWordConstructibleFromMagazine(const std::string& letter, const std::string& magazine) -> bool;
}

#endif
