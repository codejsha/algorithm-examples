#ifndef CPP_ALGORITHM_PRINT_STACK_H
#define CPP_ALGORITHM_PRINT_STACK_H

#include "linked_list.h"

#include <iostream>
#include <stack>

namespace PrintStack
{
    /**
     * \brief Print the linked list in reverse order using stack.
     * \param head the head of the stack
     */
    void PrintLinkedListInReverseOrder(
        const std::shared_ptr<LinkedList::Node<int>>& head);
}

// ----------------------------------------------------------------------------
inline void PrintStack::PrintLinkedListInReverseOrder(
    const std::shared_ptr<LinkedList::Node<int>>& head)
{
    std::stack<std::shared_ptr<LinkedList::Node<int>>> nodes;
    auto node = head;
    while (node != nullptr)
    {
        nodes.push(node);
        node = node->next;
    }

    while (!nodes.empty())
    {
        std::cout << nodes.top()->data << " ";
        nodes.pop();
    }
}

#endif
