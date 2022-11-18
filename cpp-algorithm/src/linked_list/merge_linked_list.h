#ifndef CPP_ALGORITHM_MERGE_LINKED_LIST_H
#define CPP_ALGORITHM_MERGE_LINKED_LIST_H

#include "linked_list_prototype.h"

namespace MergeLinkedList
{
    /// @brief Merge two sorted linked lists.
    /// @details In worst-case, this operation has O(n + m) time complexity, where n and m are the length of the lists.
    /// @param list1 first sorted linked list
    /// @param list2 second sorted linked list
    /// @return merged sorted linked list
    std::shared_ptr<LinkedListPrototype::ListNode<int>> MergeTwoSortedLinkedList(
        const std::shared_ptr<LinkedListPrototype::ListNode<int>>& list1,
        const std::shared_ptr<LinkedListPrototype::ListNode<int>>& list2);
}

#endif
