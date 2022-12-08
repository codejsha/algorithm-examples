#ifndef CPP_ALGORITHM_PRINT_STACK_H
#define CPP_ALGORITHM_PRINT_STACK_H

#include "linked_list.h"

namespace PrintStack
{
    /// @brief Print the linked list in reverse order using stack.
    /// @param head the head of the stack
    void PrintLinkedListInReverseOrder(const std::shared_ptr<LinkedList::Node<int>>& head);
}

#endif
