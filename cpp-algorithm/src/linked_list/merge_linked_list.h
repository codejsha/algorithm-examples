#ifndef CPP_ALGORITHM_MERGE_LINKED_LIST_H
#define CPP_ALGORITHM_MERGE_LINKED_LIST_H

#include "linked_list_prototype.h"

namespace MergeLinkedList
{
    /// @brief Merge two sorted linked lists.
    /// @details The task is to merge two sorted linked lists L1 and L2 into one sorted linked list (in place)
    /// and return the head of the merged list. In worst-case, this task has O(n + m) time complexity,
    /// where n and m are the length of the lists.
    /// @param list1 the head of the first list
    /// @param list2 the head of the second list
    /// @return the head of merged sorted linked list
    std::shared_ptr<LinkedListPrototype::ListNode<int>> MergeTwoSortedLinkedList(
        const std::shared_ptr<LinkedListPrototype::ListNode<int>>& list1,
        const std::shared_ptr<LinkedListPrototype::ListNode<int>>& list2);
}

#endif