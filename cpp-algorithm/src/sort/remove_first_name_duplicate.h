#ifndef CPP_ALGORITHM_REMOVE_FIRST_NAME_DUPLICATE_H
#define CPP_ALGORITHM_REMOVE_FIRST_NAME_DUPLICATE_H

#include <algorithm>
#include <string>
#include <vector>

namespace RemoveFirstNameDuplicate
{
    /**
     * \brief Remove the duplicate elements in a sequence.
     * \param seq sequence of names
     */
    void EliminateDuplicate(std::vector<std::string>& seq);

    /**
     * \brief Remove the duplicate elements in a sequence.
     * \param seq sequence of names
     */
    void EliminateFirstNameDuplicate(std::vector<std::string>& seq);
}

// ----------------------------------------------------------------------------
inline void RemoveFirstNameDuplicate::EliminateDuplicate(std::vector<std::string>& seq)
{
    std::ranges::sort(seq);

    // the unique() function removes the adjacent duplicate elements,
    // and returns the iterator for the new end of the range.
    const auto it = std::ranges::unique(seq).begin();
    // const auto it = std::unique(seq.begin(), seq.end());

    seq.erase(it, seq.end());
}

// ----------------------------------------------------------------------------
inline void RemoveFirstNameDuplicate::EliminateFirstNameDuplicate(std::vector<std::string>& seq)
{
    std::ranges::sort(seq);

    // the unique() function removes the adjacent duplicate elements,
    // and returns the iterator for the new end of the range.
    // the lambda function is used to compare the first name of each element.
    const auto it = std::ranges::unique(
                        seq.begin(), seq.end(), [](const auto& lhs, const auto& rhs) {
                            return lhs.substr(0, lhs.find(' ')) == rhs.substr(0, rhs.find(' '));
                        })
                        .begin();
    seq.erase(it, seq.end());
}

#endif
