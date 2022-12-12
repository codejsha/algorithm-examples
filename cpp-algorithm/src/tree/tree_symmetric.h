#ifndef CPP_ALGORITHM_TREE_SYMMETRIC_H
#define CPP_ALGORITHM_TREE_SYMMETRIC_H

#include "binary_tree.h"

namespace TreeSymmetric
{
    /// @brief Whether the binary tree is symmetric or not.
    /// @param tree the root of the tree
    /// @return whether the tree is symmetric
    auto IsSymmetric(const BinaryTree::Node<int>* tree) -> bool;

    /// @brief Check whether a binary tree is symmetric.
    /// @param left the left subtree of the tree
    /// @param right the right subtree of the tree
    /// @return whether the tree is symmetric
    auto CheckSymmetric(const BinaryTree::Node<int>* left, const BinaryTree::Node<int>* right) -> bool;
}

#endif
