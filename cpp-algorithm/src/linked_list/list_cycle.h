#ifndef CPP_ALGORITHM_LIST_CYCLE_H
#define CPP_ALGORITHM_LIST_CYCLE_H

#include "linked_list.h"

namespace ListCycle
{
    /// @brief Determine if a linked list has a cycle.
    /// @details Given a linked list, determine if it has a cycle in it.
    /// @param list the head of the linked list
    /// @return if the linked list has a cycle, return start node of the cycle, otherwise return nullptr
    auto HasCycle1(const std::shared_ptr<LinkedList::Node<int>>& list) -> std::shared_ptr<LinkedList::Node<int>>;

    /// @brief Determine if a linked list has a cycle.
    /// @details Given a linked list, determine if it has a cycle in it.
    /// This task has O(f) + O(c) = O(n) time complexity(f is count of nodes before cycle,
    /// c is length of nodes in cycle, n is total nodes in list).
    /// @param list the head of the linked list
    /// @return if the linked list has a cycle, return start node of the cycle, otherwise return nullptr
    auto HasCycle2(const std::shared_ptr<LinkedList::Node<int>>& list) -> std::shared_ptr<LinkedList::Node<int>>;

    /// @brief Determine if a linked list has a cycle.
    /// @details Given a linked list, determine if it has a cycle in it.
    /// @param list the head of the linked list
    /// @return if the linked list has a cycle, return start index of the cycle, otherwise return -1
    auto HasCycle3(const std::shared_ptr<LinkedList::Node<int>>& list) -> int;

    /// @brief Given two lists, determine if they overlap.
    /// @param list1 the head of the first list
    /// @param list2 the head of the second list
    /// @return if the two lists overlap, return the first overlapping node, otherwise return nullptr
    auto OverlappingNoCycleList(std::shared_ptr<LinkedList::Node<int>>& list1,
                                std::shared_ptr<LinkedList::Node<int>>& list2)
        -> std::shared_ptr<LinkedList::Node<int>>;

    /// @brief Given two lists with cycles, determine if they overlap.
    /// @param list1 the head of the first list
    /// @param list2 the head of the second list
    /// @return if the two lists overlap, return the first overlapping node, otherwise return nullptr
    auto OverlappingCycleList(std::shared_ptr<LinkedList::Node<int>>& list1,
                              std::shared_ptr<LinkedList::Node<int>>& list2) -> std::shared_ptr<LinkedList::Node<int>>;
}

#endif
