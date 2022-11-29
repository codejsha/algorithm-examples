#include "delete_list_node.h"

void DeleteListNode::DeleteNodeFromList(std::shared_ptr<LinkedList::Node<int>>& node_to_delete)
{
    node_to_delete->data = node_to_delete->next->data;
    node_to_delete->next = node_to_delete->next->next;
}
