#include "merge_linked_list.h"

std::shared_ptr<LinkedListPrototype::ListNode<int>> MergeLinkedList::MergeTwoSortedLinkedList(
    const std::shared_ptr<LinkedListPrototype::ListNode<int>>& list1,
    const std::shared_ptr<LinkedListPrototype::ListNode<int>>& list2)
{
    auto head = std::make_shared<LinkedListPrototype::ListNode<int>>(LinkedListPrototype::ListNode<int>{0, nullptr});
    auto tail = head;
    auto iter1 = list1;
    auto iter2 = list2;

    while (iter1 && iter2)
    {
        LinkedListPrototype::AppendNode(iter1->data < iter2->data ? &iter1 : &iter2, &tail);
    }

    tail->next = iter1 ? iter1 : iter2;

    return head->next;
}
