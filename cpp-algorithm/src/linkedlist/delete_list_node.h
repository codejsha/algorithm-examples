#ifndef CPP_ALGORITHM_DELETE_LIST_NODE_H
#define CPP_ALGORITHM_DELETE_LIST_NODE_H

#include "linked_list.h"

namespace DeleteListNode
{
    /**
     * \brief Delete a node from a singly linked list.
     * \param node_to_delete node to delete
     */
    void DeleteNodeFromList(
        std::shared_ptr<LinkedList::Node<int>>& node_to_delete);

    /**
     * \brief Delete the kth last node from a singly linked list.
     * \param list the head of the list
     * \param k kth last
     * \return the head of modified list
     */
    std::shared_ptr<LinkedList::Node<int>> DeleteNodeKthLast(
        std::shared_ptr<LinkedList::Node<int>>& list,
        int k);

    /**
     * \brief Delete duplicate nodes from a singly linked list.
     * \details The list is ordered by value in ascending order.
     * \param list the head of the list
     * \return the head of modified list
     */
    std::shared_ptr<LinkedList::Node<int>> DeleteDuplicateNode(
        std::shared_ptr<LinkedList::Node<int>>& list);
}

// ----------------------------------------------------------------------------
inline void DeleteListNode::DeleteNodeFromList(
    std::shared_ptr<LinkedList::Node<int>>& node_to_delete)
{
    node_to_delete->data = node_to_delete->next->data;
    node_to_delete->next = node_to_delete->next->next;
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> DeleteListNode::DeleteNodeKthLast(
    std::shared_ptr<LinkedList::Node<int>>& list,
    int k)
{
    const auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, list});

    auto precede = dummy_head->next;
    while (k--)
    {
        precede = precede->next;
    }

    auto follow = dummy_head;

    while (precede)
    {
        precede = precede->next;
        follow = follow->next;
    }

    follow->next = follow->next->next;

    return dummy_head->next;
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> DeleteListNode::DeleteDuplicateNode(
    std::shared_ptr<LinkedList::Node<int>>& list)
{
    auto iter = list;
    while (iter)
    {
        auto next_distinct = iter->next;
        while (next_distinct && next_distinct->data == iter->data)
        {
            next_distinct = next_distinct->next;
        }
        iter->next = next_distinct;
        iter = next_distinct;
    }
    return list;
}

#endif
