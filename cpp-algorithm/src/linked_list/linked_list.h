#ifndef CPP_ALGORITHM_LINKED_LIST_H
#define CPP_ALGORITHM_LINKED_LIST_H

#include <memory>

namespace LinkedList
{
    /// @brief A singly-linked list node.
    /// @tparam T the type of the data stored in the node
    template <typename T>
    struct Node
    {
        T data;
        std::shared_ptr<Node<T>> next;
    };

    /// @brief Append a node to the end of a linked list.
    /// @param node the head of the list
    /// @param tail the tail of the list
    inline void AppendNode(std::shared_ptr<Node<int>>* node, std::shared_ptr<Node<int>>* tail)
    {
        (*tail)->next = *node;
        *tail = *node;
        *node = (*node)->next;
    }
}

#endif
