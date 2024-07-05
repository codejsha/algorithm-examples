#include "list_arithmetic_operation.h"

auto ListArithmetic::AddTwoNumbers(std::shared_ptr<LinkedList::Node<int>>& list1,
                                   std::shared_ptr<LinkedList::Node<int>>& list2)
    -> std::shared_ptr<LinkedList::Node<int>>
{
    auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
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
