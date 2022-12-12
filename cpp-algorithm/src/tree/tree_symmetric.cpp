#include "tree_symmetric.h"

#include <array>

auto TreeSymmetric::IsSymmetric(const BinaryTree::Node<int>* tree) -> bool
{
    auto arr = std::array{1, 2, 3, 4, 5};
    auto sub_arr = std::array{arr.begin(), arr.end() - 1}; // array

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
