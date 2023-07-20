#ifndef CPP_ALGORITHM_LEAF_NODE_LIST_H
#define CPP_ALGORITHM_LEAF_NODE_LIST_H

#include "binary_tree.h"

#include <vector>

namespace LeafNodeList
{
    /**
     * \brief Create a list of leaf nodes.
     * \param root the root of the tree
     * \return leaf node list
     */
    auto CreateLeafNodeList(BinaryTree::Node<int>* root) -> std::vector<BinaryTree::Node<int>*>;
}

#endif
