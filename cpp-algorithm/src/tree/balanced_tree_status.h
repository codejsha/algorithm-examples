#ifndef CPP_ALGORITHM_BALANCED_TREE_STATUS_H
#define CPP_ALGORITHM_BALANCED_TREE_STATUS_H

#include "binary_tree.h"

namespace BalancedTree
{
    /// @brief Balanced status with height.
    struct BalancedStatus
    {
        bool is_balanced;
        int height;
    };

    /// @brief Whether the binary tree is balanced or not.
    /// @param tree the root of the tree
    /// @return whether the tree is balanced
    auto IsBalanced(const BinaryTree::ExtendedNode<int>* tree) -> bool;

    /// @brief Check whether a binary tree is balanced.
    /// @details A binary tree is balanced if the heights of the two subtrees of any node never differ by more than one.
    /// @param tree the root of the tree
    /// @return whether the tree is balanced and the height of the tree
    auto CheckBalanced(const BinaryTree::ExtendedNode<int>* tree) -> BalancedStatus;
}

#endif
