#include "merge_linked_list.h"

std::shared_ptr<LinkedList::Node<int>> MergeLinkedList::MergeTwoSortedLinkedList(
    const std::shared_ptr<LinkedList::Node<int>>& list1,
    const std::shared_ptr<LinkedList::Node<int>>& list2)
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
