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
    auto CyclicallyRightShiftList(std::shared_ptr<LinkedList::Node<int>>& list, int k)
        -> std::shared_ptr<LinkedList::Node<int>>;
}

#endif
