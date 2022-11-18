#include "reverse_list.h"

#include <utility>

std::shared_ptr<LinkedList::Node<int>> ReverseList::ReserveSubList(
    std::shared_ptr<LinkedList::Node<int>> list, int start, const int finish)
{
    auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, std::move(list)});
    auto sublist_head = dummy_head;

    int k = 1;
    while (k++ < start)
    {
        sublist_head = sublist_head->next;
    }

    auto sublist_iter = sublist_head->next;
    while (start++ < finish)
    {
        auto temp = sublist_iter->next;
        sublist_iter->next = temp->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
    }

    return dummy_head->next;
}
