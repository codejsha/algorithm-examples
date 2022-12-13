#include "lowest_common_ancestor.h"

int GetDepth(const BinarySearchTree::Node<int>* node)
{
    auto depth = 0;
    while (node->parent)
    {
        ++depth;
        node = node->parent;
    }
    return depth;
}

auto LowestCommonAncestor::FindLowestCommonAncestor(
    const BinaryTree::Node<int>* tree,
    const BinaryTree::Node<int>* node1,
    const BinaryTree::Node<int>* node2)
    -> const BinaryTree::Node<int>*
{
    return LcaHelper(tree, node1, node2).ancestor;
}

auto LowestCommonAncestor::LcaHelper(
    const BinaryTree::Node<int>* tree,
    const BinaryTree::Node<int>* node1,
    const BinaryTree::Node<int>* node2)
    -> Status
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
    const auto num_target_nodes = left_result.num_target_nodes + right_result.num_target_nodes
                                  + (tree == node1) + (tree == node2);
    return {num_target_nodes, num_target_nodes == 2 ? tree : nullptr};
}

auto LowestCommonAncestor::FindLowestCommonAncestor2(
    const BinarySearchTree::Node<int>* tree,
    const BinarySearchTree::Node<int>* node1,
    const BinarySearchTree::Node<int>* node2)
    -> const BinarySearchTree::Node<int>*
{
    auto iter1 = node1;
    auto iter2 = node2;
    const auto depth1 = GetDepth(iter1);
    const auto depth2 = GetDepth(iter2);

    if (depth1 > depth2)
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
