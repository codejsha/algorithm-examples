#ifndef CPP_ALGORITHM_BALANCED_TREE_STATUS_H
#define CPP_ALGORITHM_BALANCED_TREE_STATUS_H

#include "binary_tree.h"

#include <algorithm>

namespace BalancedTree
{
    /**
     * \brief Balanced status with height.
     */
    struct BalancedStatus
    {
        bool is_balanced;
        int height;
    };

    /**
     * \brief Whether the binary tree is balanced or not.
     * \param tree the root of the tree
     * \return whether the tree is balanced
     */
    bool IsBalanced(
        const BinaryTree::ExtendedNode<int>* tree);

    /**
     * \brief Check whether a binary tree is balanced.
     * \details A binary tree is balanced if the heights of the two subtrees of any node never differ by more than one.
     * \param tree the root of the tree
     * \return whether the tree is balanced and the height of the tree
     */
    BalancedStatus CheckBalanced(
        const BinaryTree::ExtendedNode<int>* tree);
}

// ----------------------------------------------------------------------------
inline bool BalancedTree::IsBalanced(
    const BinaryTree::ExtendedNode<int>* tree)
{
    return CheckBalanced(tree).is_balanced;
}

// ----------------------------------------------------------------------------
inline BalancedTree::BalancedStatus BalancedTree::CheckBalanced(
    const BinaryTree::ExtendedNode<int>* tree)
{
    if (tree == nullptr)
    {
        return {true, -1};
    }

    const auto [is_left_balanced, left_height] = CheckBalanced(tree->left);
    if (!is_left_balanced)
    {
        return {false, 0};
    }

    const auto [is_right_balanced, right_height] = CheckBalanced(tree->right);
    if (!is_right_balanced)
    {
        return {false, 0};
    }

    const bool is_balanced = std::abs(left_height - right_height) <= 1;
    const int height = std::max(left_height, right_height) + 1;
    return {is_balanced, height};
}

#endif
