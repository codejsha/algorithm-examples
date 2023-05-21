#ifndef CPP_ALGORITHM_COMBINATION_H
#define CPP_ALGORITHM_COMBINATION_H

#include <string>
#include <vector>

namespace Combination
{
    /**
     * \brief Generate all possible combinations of integer elements in a sequence.
     * \param seq sequence of integer elements
     * \param k size of the subset
     * \return combinations of integer elements
     */
    auto GenerateCombination(const std::vector<int>& seq, int k) -> std::vector<std::vector<int>>;

    /**
     * \brief Generate all possible combinations of string elements in a sequence.
     * \param seq sequence of string elements
     * \param k size of the subset
     * \return combinations of string elements
     */
    auto GenerateCombination(const std::vector<std::string>& seq, int k) -> std::vector<std::vector<std::string>>;

    /**
     * \brief Generate all possible combinations of chars in a string.
     * \param str given string
     * \param k size of the subset
     * \return combinations of chars in a string
     */
    auto GenerateCombination(const std::string& str, int k) -> std::vector<std::string>;
}

#endif
