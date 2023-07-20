#ifndef CPP_ALGORITHM_LIST_ARITHMETIC_OPERATION_H
#define CPP_ALGORITHM_LIST_ARITHMETIC_OPERATION_H

#include "linked_list.h"

namespace ListArithmetic
{
    /**
     * \brief Add two numbers represented by linked lists.
     * \param list1 the head of the first list
     * \param list2 the head of the second list
     * \return the head of the sum list
     */
    auto AddTwoNumbers(std::shared_ptr<LinkedList::Node<int>>& list1, std::shared_ptr<LinkedList::Node<int>>& list2)
        -> std::shared_ptr<LinkedList::Node<int>>;
}

#endif
