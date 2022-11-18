#ifndef CPP_ALGORITHM_LINKED_LIST_PROTOTYPE_H
#define CPP_ALGORITHM_LINKED_LIST_PROTOTYPE_H

#include <memory>

namespace LinkedListPrototype
{
    /// @brief A singly-linked list node.
    /// @tparam T the type of the data stored in the node
    template <typename T>
    struct ListNode
    {
        T data;
        std::shared_ptr<ListNode<T>> next;
    };

    /// @brief Append a node to the end of a linked list.
    /// @param node the head of the list
    /// @param tail the tail of the list
    inline void AppendNode(std::shared_ptr<ListNode<int>>* node, std::shared_ptr<ListNode<int>>* tail)
    {
        (*tail)->next = *node;
        *tail = *node;
        *node = (*node)->next;
    }
}

#endif
