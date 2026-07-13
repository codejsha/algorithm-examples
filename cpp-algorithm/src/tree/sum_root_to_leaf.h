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
    int SumRootToLeafDecimal(
        const BinaryTree::Node<int>* tree);

    /**
     * \brief Sum of all binary numbers represented by root-to-leaf paths.
     * \param tree the root of the tree
     * \return the sum of binary numbers represented by root-to-leaf paths
     */
    int SumRootToLeafBinary(
        const BinaryTree::Node<int>* tree);

    /**
     * \brief Whether the tree has a root-leaf path equal to the given sum.
     * \details Determine if the given sum equals the sum of the keys in the path.
     * \param tree the root of the tree
     * \param partial_sum the partial sum of the keys in the path
     * \return true if the tree has a root-leaf path equal to the given sum, false otherwise
     */
    bool HasKeySum(
        const BinaryTree::Node<int>* tree,
        int partial_sum);
}

// ----------------------------------------------------------------------------
inline int SumRootToLeaf(
    const BinaryTree::Node<int>* tree,
    int partial_path_sum,
    const int base)
{
    if (tree == nullptr)
    {
        return 0;
    }

    // If this is a leaf node, return the current path sum.
    partial_path_sum = partial_path_sum * base + tree->key;
    if (tree->left == nullptr && tree->right == nullptr)
    {
        return partial_path_sum;
    }

    // If this is not a leaf node, return the sum of the left and right subtree sums.
    return SumRootToLeaf(tree->left, partial_path_sum, base)
           + SumRootToLeaf(tree->right, partial_path_sum, base);
}

// ----------------------------------------------------------------------------
inline int TreeSumRootToLeaf::SumRootToLeafDecimal(
    const BinaryTree::Node<int>* tree)
{
    return SumRootToLeaf(tree, 0, 10);
}

// ----------------------------------------------------------------------------
inline int TreeSumRootToLeaf::SumRootToLeafBinary(
    const BinaryTree::Node<int>* tree)
{
    return SumRootToLeaf(tree, 0, 2);
}

// ----------------------------------------------------------------------------
inline bool TreeSumRootToLeaf::HasKeySum(
    const BinaryTree::Node<int>* tree,
    const int partial_sum)
{
    if (tree == nullptr)
    {
        return false;
    }
    if (tree->left == nullptr && tree->right == nullptr)
    {
        return partial_sum == tree->key;
    }
    return HasKeySum(tree->left, partial_sum - tree->key)
           || HasKeySum(tree->right, partial_sum - tree->key);
}

#endif
