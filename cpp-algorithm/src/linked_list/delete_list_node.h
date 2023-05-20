#ifndef CPP_ALGORITHM_DELETE_LIST_NODE_H
#define CPP_ALGORITHM_DELETE_LIST_NODE_H

#include "linked_list.h"

namespace DeleteListNode
{
    /// @brief Delete a node from a singly linked list.
    /// @param node_to_delete node to delete
    void DeleteNodeFromList(std::shared_ptr<LinkedList::Node<int>>& node_to_delete);

    /// @brief Delete the kth last node from a singly linked list.
    /// @param list the head of the list
    /// @param k kth last
    /// @return the head of modified list
    auto DeleteNodeKthLast(std::shared_ptr<LinkedList::Node<int>>& list, int k)
        -> std::shared_ptr<LinkedList::Node<int>>;

    /// @brief Delete duplicate nodes from a singly linked list.
    /// @details The list is ordered by value in ascending order.
    /// @param list the head of the list
    /// @return the head of modified list
    auto DeleteDuplicateNode(std::shared_ptr<LinkedList::Node<int>>& list) -> std::shared_ptr<LinkedList::Node<int>>;
}

#endif
