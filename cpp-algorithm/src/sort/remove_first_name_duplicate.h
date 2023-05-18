#ifndef CPP_ALGORITHM_REMOVE_FIRST_NAME_DUPLICATE_H
#define CPP_ALGORITHM_REMOVE_FIRST_NAME_DUPLICATE_H

#include <string>
#include <vector>

namespace RemoveFirstNameDuplicate
{
    /**
     * @brief Remove the duplicate elements in a sequence.
     * @param seq sequence of names
     */
    void EliminateDuplicate(std::vector<std::string>& seq);

    /**
     * @brief Remove the duplicate elements in a sequence.
     * @param seq sequence of names
     */
    void EliminateFirstNameDuplicate(std::vector<std::string>& seq);
}

#endif
