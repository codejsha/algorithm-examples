#include "shift_list.h"

auto ShiftList::CyclicallyRightShiftList(std::shared_ptr<LinkedList::Node<int>>& list, int k) -> std::shared_ptr<LinkedList::Node<int>>
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
    auto steps_to_new_head = length - k;
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
