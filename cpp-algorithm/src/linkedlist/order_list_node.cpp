#include "order_list_node.h"

auto OrderListNode::ListPivoting(const std::shared_ptr<LinkedList::Node<int>>& list, int x)
    -> std::shared_ptr<LinkedList::Node<int>>
{
    const auto less_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    const auto equal_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    const auto greater_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});

    auto less_iter = less_head;
    auto equal_iter = equal_head;
    auto greater_iter = greater_head;

    // Partition the list into three.
    auto iter = list;
    while (iter)
    {
        if (iter->data < x)
        {
            less_iter->next = iter;
            less_iter = less_iter->next;
        }
        else if (iter->data == x)
        {
            equal_iter->next = iter;
            equal_iter = equal_iter->next;
        }
        else
        {
            greater_iter->next = iter;
            greater_iter = greater_iter->next;
        }

        iter = iter->next;
    }

    // Concatenate the three lists.
    greater_iter->next = nullptr;
    equal_iter->next = greater_head->next;
    less_iter->next = equal_head->next;

    return less_head->next;
}
