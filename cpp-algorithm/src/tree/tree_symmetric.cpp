#include "tree_symmetric.h"

auto TreeSymmetric::IsSymmetric(const BinaryTree::Node<int>* tree) -> bool
{
    return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}

auto TreeSymmetric::CheckSymmetric(const BinaryTree::Node<int>* left, const BinaryTree::Node<int>* right) -> bool
{
    if (left == nullptr || right == nullptr)
    {
        return left == right;
    }

    if (left->key != right->key)
    {
        return false;
    }

    return CheckSymmetric(left->left, right->right)
           && CheckSymmetric(left->right, right->left);
}
