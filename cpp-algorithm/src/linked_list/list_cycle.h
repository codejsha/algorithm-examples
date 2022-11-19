#ifndef CPP_ALGORITHM_LIST_CYCLE_H
#define CPP_ALGORITHM_LIST_CYCLE_H

#include "linked_list.h"

namespace ListCycle
{
    /// @brief Determine if a linked list has a cycle.
    /// @details Given a linked list, determine if it has a cycle in it.
    /// @param list the head of the linked list
    /// @return if the linked list has a cycle, return start node of the cycle, otherwise return nullptr
    std::shared_ptr<LinkedList::Node<int>> HasCycle1(const std::shared_ptr<LinkedList::Node<int>>& list);

    /// @brief Determine if a linked list has a cycle.
    /// @details Given a linked list, determine if it has a cycle in it.
    /// This task has O(f) + O(c) = O(n) time complexity(f is count of nodes before cycle,
    /// c is length of nodes in cycle, n is total nodes in list).
    /// @param list the head of the linked list
    /// @return if the linked list has a cycle, return start node of the cycle, otherwise return nullptr
    std::shared_ptr<LinkedList::Node<int>> HasCycle2(const std::shared_ptr<LinkedList::Node<int>>& list);

    /// @brief Determine if a linked list has a cycle.
    /// @details Given a linked list, determine if it has a cycle in it.
    /// @param list the head of the linked list
    /// @return if the linked list has a cycle, return start index of the cycle, otherwise return -1
    int HasCycle3(const std::shared_ptr<LinkedList::Node<int>>& list);
}

#endif
