#include "sum_root_to_leaf.h"

auto SumRootToLeaf(const BinaryTree::Node<int>* tree, int partial_path_sum, int base) -> int
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
auto TreeSumRootToLeaf::SumRootToLeafDecimal(const BinaryTree::Node<int>* tree) -> int
{
    return SumRootToLeafHelperDecimal(tree, 0);
}

auto TreeSumRootToLeaf::SumRootToLeafHelperDecimal(const BinaryTree::Node<int>* tree, int partial_path_sum) -> int
{
    return SumRootToLeaf(tree, partial_path_sum, 10);
}

auto TreeSumRootToLeaf::SumRootToLeafBinary(const BinaryTree::Node<int>* tree) -> int
{
    return SumRootToLeafHelperBinary(tree, 0);
}

auto TreeSumRootToLeaf::SumRootToLeafHelperBinary(const BinaryTree::Node<int>* tree, int partial_path_sum) -> int
{
    return SumRootToLeaf(tree, partial_path_sum, 2);
}

auto TreeSumRootToLeaf::HasKeySum(const BinaryTree::Node<int>* tree, const int partial_sum) -> bool
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
