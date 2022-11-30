#include "delete_list_node.h"

void DeleteListNode::DeleteNodeFromList(std::shared_ptr<LinkedList::Node<int>>& node_to_delete)
{
    node_to_delete->data = node_to_delete->next->data;
    node_to_delete->next = node_to_delete->next->next;
}

auto DeleteListNode::DeleteNodeKthLast(std::shared_ptr<LinkedList::Node<int>>& list, int k) -> std::shared_ptr<LinkedList::Node<int>>
{
    auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, list});

    auto precede = dummy_head->next;
    while (k--)
    {
        precede = precede->next;
    }

    auto follow = dummy_head;

    while (precede)
    {
        precede = precede->next;
        follow = follow->next;
    }

    follow->next = follow->next->next;

    return dummy_head->next;
}
