#ifndef CPP_ALGORITHM_BINARY_TREE_EXTERIOR_H
#define CPP_ALGORITHM_BINARY_TREE_EXTERIOR_H

#include "binary_tree.h"

#include <vector>

namespace BinaryTreeExterior
{
    /**
     * \brief Create a list of exterior nodes.
     * \param root the root of the tree
     * \return exterior node list
     */
    auto CreateExteriorNodeList(BinaryTree::Node<char>* root) -> std::vector<BinaryTree::Node<char>*>;
}

#endif
