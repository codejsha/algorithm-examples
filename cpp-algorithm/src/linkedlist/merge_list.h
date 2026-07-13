#ifndef CPP_ALGORITHM_MERGE_LIST_H
#define CPP_ALGORITHM_MERGE_LIST_H

#include "linked_list.h"

#include <vector>

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
    std::shared_ptr<LinkedList::Node<int>> MergeTwoSortedLinkedList(
        const std::shared_ptr<LinkedList::Node<int>>& list1,
        const std::shared_ptr<LinkedList::Node<int>>& list2);

    /**
     * \brief Merge even and odd nodes in a singly linked list.
     * \param list the head of the list
     * \return the head of the even-odd merged list
     */
    std::shared_ptr<LinkedList::Node<int>> MergeEvenOddLinkedList(
        const std::shared_ptr<LinkedList::Node<int>>& list);
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> MergeList::MergeTwoSortedLinkedList(
    const std::shared_ptr<LinkedList::Node<int>>& list1,
    const std::shared_ptr<LinkedList::Node<int>>& list2)
{
    const auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    auto tail = dummy_head;
    auto iter1 = list1;
    auto iter2 = list2;

    while (iter1 && iter2)
    {
        LinkedList::AppendNode(iter1->data < iter2->data ? &iter1 : &iter2, &tail);
    }

    tail->next = iter1 ? iter1 : iter2;

    return dummy_head->next;
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> MergeList::MergeEvenOddLinkedList(
    const std::shared_ptr<LinkedList::Node<int>>& list)
{
    if (list == nullptr || list->next == nullptr)
    {
        return list;
    }

    const auto even_dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    const auto odd_dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    auto tails = std::vector{even_dummy_head, odd_dummy_head};
    int turn = 0;

    for (auto iter = list; iter; iter = iter->next)
    {
        tails[turn]->next = iter;
        tails[turn] = tails[turn]->next;
        turn ^= 1;
    }

    tails[1]->next = nullptr;
    tails[0]->next = odd_dummy_head->next;

    return even_dummy_head->next;
}

#endif
