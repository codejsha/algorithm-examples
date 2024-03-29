#ifndef CPP_ALGORITHM_MERGE_LIST_H
#define CPP_ALGORITHM_MERGE_LIST_H

#include "linked_list.h"

namespace MergeList
{
    /**
     * \brief Merge two sorted linked lists.
     * \details The task is to merge two sorted linked lists L1 and L2 into one sorted linked list (in place)
     * and return the head of the merged list. In worst-case, this task has O(n + m) time complexity,
     * where n and m are the length of the lists.
     * \param list1 the head of the first list
     * \param list2 the head of the second list
     * \return the head of merged sorted linked list
     */
    auto MergeTwoSortedLinkedList(const std::shared_ptr<LinkedList::Node<int>>& list1,
                                  const std::shared_ptr<LinkedList::Node<int>>& list2)
        -> std::shared_ptr<LinkedList::Node<int>>;

    /**
     * \brief Merge even and odd nodes in a singly linked list.
     * \param list the head of the list
     * \return the head of the even-odd merged list
     */
    auto MergeEvenOddLinkedList(const std::shared_ptr<LinkedList::Node<int>>& list)
        -> std::shared_ptr<LinkedList::Node<int>>;
}

#endif
