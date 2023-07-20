#ifndef CPP_ALGORITHM_SUM_ROOT_TO_LEAF_H
#define CPP_ALGORITHM_SUM_ROOT_TO_LEAF_H

#include "binary_tree.h"

namespace TreeSumRootToLeaf
{
    /**
     * \brief Sum of all root-to-leaf paths.
     * \param tree the root of the tree
     * \return the sum of all root-to-leaf paths
     */
    auto SumRootToLeafDecimal(const BinaryTree::Node<int>* tree) -> int;

    /**
     * \brief Sum of all binary numbers represented by root-to-leaf paths.
     * \param tree the root of the tree
     * \return the sum of binary numbers represented by root-to-leaf paths
     */
    auto SumRootToLeafBinary(const BinaryTree::Node<int>* tree) -> int;

    /**
     * \brief Whether the tree has a root-leaf path equal to the given sum.
     * \details Determine if the given sum equals the sum of the keys in the path.
     * \param tree the root of the tree
     * \param partial_sum the partial sum of the keys in the path
     * \return true if the tree has a root-leaf path equal to the given sum, false otherwise
     */
    auto HasKeySum(const BinaryTree::Node<int>* tree, int partial_sum) -> bool;
}

#endif
