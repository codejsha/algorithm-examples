#include "lowest_common_ancestor.h"

#include <algorithm>

/// @brief Find the lowest common ancestor and the number of target nodes in the subtree.
/// @param tree the root of the tree
/// @param node1 the first node
/// @param node2 the second node
/// @return the number of target nodes and the lowest common ancestor of the two nodes
auto LcaHelper(const BinaryTree::Node<int>* tree, const BinaryTree::Node<int>* node1,
               const BinaryTree::Node<int>* node2) -> LowestCommonAncestor::Status
{
    if (tree == nullptr)
    {
        return {0, nullptr};
    }
    const auto left_result = LcaHelper(tree->left, node1, node2);
    if (left_result.num_target_nodes == 2)
    {
        return left_result;
    }
    const auto right_result = LcaHelper(tree->right, node1, node2);
    if (right_result.num_target_nodes == 2)
    {
        return right_result;
    }
    const auto num_target_nodes =
        left_result.num_target_nodes + right_result.num_target_nodes + (tree == node1) + (tree == node2);
    return {num_target_nodes, num_target_nodes == 2 ? tree : nullptr};
}

auto LowestCommonAncestor::FindLowestCommonAncestor(const BinaryTree::Node<int>* tree,
                                                    const BinaryTree::Node<int>* node1,
                                                    const BinaryTree::Node<int>* node2) -> const BinaryTree::Node<int>*
{
    return LcaHelper(tree, node1, node2).ancestor;
}

auto LowestCommonAncestor::FindLowestCommonAncestor2(const BinaryTree::ExtendedNode<int>* tree,
                                                     const BinaryTree::ExtendedNode<int>* node1,
                                                     const BinaryTree::ExtendedNode<int>* node2)
    -> const BinaryTree::ExtendedNode<int>*
{
    auto iter1 = node1;
    auto iter2 = node2;
    const auto depth1 = ExtendedNodeTreeDepth(iter1);
    const auto depth2 = ExtendedNodeTreeDepth(iter2);

    if (depth2 > depth1)
    {
        std::swap(iter1, iter2);
    }

    auto depth_diff = std::abs(depth1 - depth2);
    while (depth_diff--)
    {
        iter1 = iter1->parent;
    }

    while (iter1 != iter2 && iter1 && iter2)
    {
        iter1 = iter1->parent;
        iter2 = iter2->parent;
    }

    return iter1;
}
