#ifndef CPP_ALGORITHM_OPTIMIZED_LCA_H
#define CPP_ALGORITHM_OPTIMIZED_LCA_H

#include "binary_tree.h"

namespace OptimizedLca
{
    /**
     * \brief Find the lowest common ancestor of two nodes in a binary tree.
     * \details Traverse up node1 and node2 together until they meet.
     * \param node1 the first node
     * \param node2 the second node
     * \return the lowest common ancestor of node1 and node2
     */
    auto FindOptimizedLowestCommonAncestor(const BinaryTree::ExtendedNode<int>* node1,
                                           const BinaryTree::ExtendedNode<int>* node2)
        -> const BinaryTree::ExtendedNode<int>*;
}
#endif
