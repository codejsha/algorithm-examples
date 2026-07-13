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
    std::shared_ptr<LinkedList::Node<int>> AddTwoNumbers(
        std::shared_ptr<LinkedList::Node<int>>& list1,
        std::shared_ptr<LinkedList::Node<int>>& list2);
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> ListArithmetic::AddTwoNumbers(
    std::shared_ptr<LinkedList::Node<int>>& list1,
    std::shared_ptr<LinkedList::Node<int>>& list2)
{
    const auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    auto iter = dummy_head;
    int carry = 0;

    while (list1 || list2 || carry)
    {
        auto sum = carry;
        if (list1)
        {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2)
        {
            sum += list2->data;
            list2 = list2->next;
        }

        iter->next = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{sum % 10, nullptr});
        iter = iter->next;
        carry = sum / 10;
    }

    return dummy_head->next;
}

#endif
