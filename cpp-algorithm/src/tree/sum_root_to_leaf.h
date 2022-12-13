#ifndef CPP_ALGORITHM_SUM_ROOT_TO_LEAF_H
#define CPP_ALGORITHM_SUM_ROOT_TO_LEAF_H

#include "binary_tree.h"

namespace TreeSumRootToLeaf
{
    /// @brief Sum of all root-to-leaf paths.
    /// @param tree the root of the tree
    /// @return the sum of all root-to-leaf paths
    auto SumRootToLeafDecimal(const BinaryTree::Node<int>* tree) -> int;

    /// @brief Partial sum of the root-to-leaf paths.
    /// @param tree the root of the tree
    /// @param partial_path_sum the partial path sum
    /// @return the partial sum of all root-to-leaf paths
    auto SumRootToLeafHelperDecimal(const BinaryTree::Node<int>* tree, int partial_path_sum) -> int;

    /// @brief Sum of binary numbers represented by root-to-leaf paths.
    /// @param tree the root of the tree
    /// @return the sum of binary numbers represented by root-to-leaf paths
    auto SumRootToLeafBinary(const BinaryTree::Node<int>* tree) -> int;

    /// @brief Partial sum of binary numbers represented by root-to-leaf paths
    /// @param tree the root of the tree
    /// @param partial_path_sum the partial path sum
    /// @return the partial sum of binary numbers represented by root-to-leaf paths
    auto SumRootToLeafHelperBinary(const BinaryTree::Node<int>* tree, int partial_path_sum) -> int;
}

#endif
