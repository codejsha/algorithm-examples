#ifndef CPP_ALGORITHM_ORDER_LIST_NODE_H
#define CPP_ALGORITHM_ORDER_LIST_NODE_H

#include "linked_list.h"

namespace OrderListNode
{
    /**
     * \brief Rearrange nodes smaller than pivot to the left and larger than pivot to the right.
     * \param list the head of the list
     * \param x pivot
     * \return the head of the rearranged list
     */
    std::shared_ptr<LinkedList::Node<int>> ListPivoting(
        const std::shared_ptr<LinkedList::Node<int>>& list,
        int x);
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> OrderListNode::ListPivoting(
    const std::shared_ptr<LinkedList::Node<int>>& list,
    int x)
{
    const auto less_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    const auto equal_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    const auto greater_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});

    auto less_iter = less_head;
    auto equal_iter = equal_head;
    auto greater_iter = greater_head;

    // Partition the list into three.
    auto iter = list;
    while (iter)
    {
        if (iter->data < x)
        {
            less_iter->next = iter;
            less_iter = less_iter->next;
        }
        else if (iter->data == x)
        {
            equal_iter->next = iter;
            equal_iter = equal_iter->next;
        }
        else
        {
            greater_iter->next = iter;
            greater_iter = greater_iter->next;
        }

        iter = iter->next;
    }

    // Concatenate the three lists.
    greater_iter->next = nullptr;
    equal_iter->next = greater_head->next;
    less_iter->next = equal_head->next;

    return less_head->next;
}

#endif
