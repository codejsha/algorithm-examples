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
    void PopulateRightSibling(
        const BinaryTree::NextExtendedNode<char>* tree);
}

// ----------------------------------------------------------------------------
inline void RightSibling::PopulateRightSibling(
    const BinaryTree::NextExtendedNode<char>* tree)
{
    // if child level is not null, populate the next pointer of the child level
    while (tree && tree->left)
    {
        auto node = tree;
        while (node)
        {
            node->left->next = node->right;

            // if current node has sibling, set the sibling of the right child
            // to the left child of the sibling of the current node
            if (node->next)
            {
                node->right->next = node->next->left;
            }

            node = node->next;
        }
        tree = tree->left;
    }
}

#endif
