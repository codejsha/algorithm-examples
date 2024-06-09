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
    auto ListPivoting(const std::shared_ptr<LinkedList::Node<int>>& list, int x)
        -> std::shared_ptr<LinkedList::Node<int>>;
}

#endif
