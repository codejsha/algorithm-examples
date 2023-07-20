#ifndef CPP_ALGORITHM_RIGHT_SIBLING_H
#define CPP_ALGORITHM_RIGHT_SIBLING_H

#include "binary_tree.h"

namespace RightSibling
{
    /**
     * \brief Populate the right sibling of a binary tree.
     * \details Given a binary tree, populate each next pointer to point to its next right node (right sibling node).
     * If there is no next right node, the next pointer should be set to NULL.
     * \note The given tree is perfect binary tree.
     * \param tree the tree to be processed
     */
    void PopulateRightSibling(const BinaryTree::NextExtendedNode<char>* tree);
}

#endif
