#ifndef CPP_ALGORITHM_TREE_SYMMETRIC_H
#define CPP_ALGORITHM_TREE_SYMMETRIC_H

#include "binary_tree.h"

namespace TreeSymmetric
{
    /**
     * \brief Whether the binary tree is symmetric or not.
     * \param tree the root of the tree
     * \return whether the tree is symmetric
     */
    bool IsSymmetric(
        const BinaryTree::Node<int>* tree);

    /**
     * \brief Check whether a binary tree is symmetric.
     * \param left the left subtree of the tree
     * \param right the right subtree of the tree
     * \return whether the tree is symmetric
     */
    bool CheckSymmetric(
        const BinaryTree::Node<int>* left,
        const BinaryTree::Node<int>* right);
}

// ----------------------------------------------------------------------------
inline bool TreeSymmetric::IsSymmetric(
    const BinaryTree::Node<int>* tree)
{
    return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}

// ----------------------------------------------------------------------------
inline bool TreeSymmetric::CheckSymmetric(
    const BinaryTree::Node<int>* left,
    const BinaryTree::Node<int>* right)
{
    if (left == nullptr || right == nullptr)
    {
        return left == right;
    }

    if (left->key != right->key)
    {
        return false;
    }

    return CheckSymmetric(left->left, right->right)
           && CheckSymmetric(left->right, right->left);
}

#endif
