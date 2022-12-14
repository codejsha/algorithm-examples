#ifndef CPP_ALGORITHM_LOWEST_COMMON_ANCESTOR_H
#define CPP_ALGORITHM_LOWEST_COMMON_ANCESTOR_H

#include "binary_tree.h"

namespace LowestCommonAncestor
{
    /// @brief Status of the lowest common ancestor.
    struct Status
    {
        int num_target_nodes;
        const BinaryTree::Node<int>* ancestor;
    };

    /// @brief Find the lowest common ancestor of two nodes in a binary tree.
    /// @param tree the root of the tree
    /// @param node1 the first node
    /// @param node2 the second node
    /// @return the lowest common ancestor of the two nodes
    auto FindLowestCommonAncestor(
        const BinaryTree::Node<int>* tree,
        const BinaryTree::Node<int>* node1,
        const BinaryTree::Node<int>* node2)
        -> const BinaryTree::Node<int>*;

    /// @brief Find the lowest common ancestor of two nodes in a binary tree. The nodes have parent pointers.
    /// @param tree the root of the tree
    /// @param node1 the first node
    /// @param node2 the second node
    /// @return the lowest common ancestor of the two nodes
    auto FindLowestCommonAncestor2(
        const BinaryTree::ExtendedNode<int>* tree,
        const BinaryTree::ExtendedNode<int>* node1,
        const BinaryTree::ExtendedNode<int>* node2)
        -> const BinaryTree::ExtendedNode<int>*;
}

#endif
