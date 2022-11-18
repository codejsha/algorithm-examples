#ifndef CPP_ALGORITHM_REVERSE_LIST_H
#define CPP_ALGORITHM_REVERSE_LIST_H

#include "linked_list.h"

namespace ReverseList
{
    /// @brief Rearranges the sublist of the list in reverse order.
    /// @details The sublist is defined by the start and finish indices.
    /// This task has O(f) time complexity, f is the index of the finish node.
    /// @param list the head of the list
    /// @param start start index of the sublist
    /// @param finish end index of the sublist
    /// @return the head of the list
    std::shared_ptr<LinkedList::Node<int>> ReserveSubList(std::shared_ptr<LinkedList::Node<int>> list, int start, int finish);
}

#endif
