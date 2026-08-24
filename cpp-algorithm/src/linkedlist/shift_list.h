#ifndef CPP_ALGORITHM_SHIFT_LIST_H
#define CPP_ALGORITHM_SHIFT_LIST_H

#include "linked_list.h"

namespace ShiftList
{
    /**
     * \brief Implement cyclic right shift for a singly linked list.
     * Given a singly linked list and an integer k, cyclically right shift the list by k.
     * \details Connect the tail to the head to make a cycle,
     * apply shift operation to the head to make a cycle, disconnect the cycle.
     * For example, 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.
     * \param list the head of the list
     * \param k k shifts
     * \return the head of modified list
     */
    std::shared_ptr<LinkedList::Node<int>> CyclicallyRightShiftList(
        std::shared_ptr<LinkedList::Node<int>>& list,
        int k);
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> ShiftList::CyclicallyRightShiftList(
    std::shared_ptr<LinkedList::Node<int>>& list,
    int k)
{
    // empty list
    if (!list)
    {
        return list;
    }

    // get the tail and compute the length of the list
    auto tail = list;
    int length = 1;
    while (tail->next)
    {
        ++length;
        tail = tail->next;
    }

    // no shift (k is a multiple of length)
    k %= length;
    if (k == 0)
    {
        return list;
    }

    // connect the tail to the head to make a cycle
    tail->next = list;
    // apply shift operation
    int steps_to_new_head = length - k;
    auto new_tail = tail;
    while (steps_to_new_head--)
    {
        new_tail = new_tail->next;
    }
    auto new_head = new_tail->next;

    // disconnect the cycle
    new_tail->next = nullptr;

    return new_head;
}

#endif
