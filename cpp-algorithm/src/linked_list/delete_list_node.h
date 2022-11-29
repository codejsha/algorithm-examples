#ifndef CPP_ALGORITHM_DELETE_LIST_NODE_H
#define CPP_ALGORITHM_DELETE_LIST_NODE_H

#include "linked_list.h"

namespace DeleteListNode
{
    /// @brief Delete a node from a singly linked list.
    /// @param node_to_delete node to delete
    void DeleteNodeFromList(std::shared_ptr<LinkedList::Node<int>>& node_to_delete);
}

#endif
