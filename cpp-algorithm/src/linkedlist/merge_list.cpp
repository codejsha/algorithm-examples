#include "merge_list.h"

#include <vector>

auto MergeList::MergeTwoSortedLinkedList(const std::shared_ptr<LinkedList::Node<int>>& list1,
                                         const std::shared_ptr<LinkedList::Node<int>>& list2)
    -> std::shared_ptr<LinkedList::Node<int>>
{
    auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    auto tail = dummy_head;
    auto iter1 = list1;
    auto iter2 = list2;

    while (iter1 && iter2)
    {
        LinkedList::AppendNode(iter1->data < iter2->data ? &iter1 : &iter2, &tail);
    }

    tail->next = iter1 ? iter1 : iter2;

    return dummy_head->next;
}

auto MergeList::MergeEvenOddLinkedList(const std::shared_ptr<LinkedList::Node<int>>& list)
    -> std::shared_ptr<LinkedList::Node<int>>
{
    if (list == nullptr || list->next == nullptr)
    {
        return list;
    }

    auto even_dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    auto odd_dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, nullptr});
    auto tails = std::vector{even_dummy_head, odd_dummy_head};
    auto turn = 0;

    for (auto iter = list; iter; iter = iter->next)
    {
        tails[turn]->next = iter;
        tails[turn] = tails[turn]->next;
        turn ^= 1;
    }

    tails[1]->next = nullptr;
    tails[0]->next = odd_dummy_head->next;

    return even_dummy_head->next;
}
