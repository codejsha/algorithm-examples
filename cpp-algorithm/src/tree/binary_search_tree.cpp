#include "binary_search_tree.h"
#include "util.h"
#include <iostream>
#include <vector>

void tree::BinarySearchTree::Insert(const int value)
{
    if (root_ == nullptr)
    {
        root_ = new Node(value);
        return;
    }
    Insert(root_, value);
}

void tree::BinarySearchTree::Insert(Node*& node, const int value)
{
    if (node == nullptr)
    {
        node = new Node(value);
        return;
    }
    if (value < node->value)
    {
        Insert(node->left, value);
        node->left->parent = node;
    }
    else
    {
        Insert(node->right, value);
        node->right->parent = node;
    }
}

void tree::BinarySearchTree::Delete(const int value)
{
    if (root_ == nullptr)
    {
        return;
    }
    Delete(root_, value);
}

void tree::BinarySearchTree::Delete(Node*& node, const int value)
{
    if (node == nullptr)
    {
        return;
    }
    if (value < node->value)
    {
        Delete(node->left, value);
    }
    else if (value > node->value)
    {
        Delete(node->right, value);
    }
    else
    {
        // leaf node
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        // node does not have left child node
        else if (node->left == nullptr)
        {
            const auto temp = node;
            node = node->right;
            node->parent = temp->parent;
            delete temp;
        }
        // node does not have right child node
        else if (node->right == nullptr)
        {
            const auto temp = node;
            node = node->left;
            node->parent = temp->parent;
            delete temp;
        }
        // node has left and right child node
        else
        {
            const auto temp = GetMinimum(node->right);
            node->value = temp->value;
            Delete(node->right, temp->value);
        }
    }
}

std::vector<int> tree::BinarySearchTree::InorderTreeWalk()
{
    std::vector<int> values;
    InorderTreeWalk(root_, values);
    return values;
}

void tree::BinarySearchTree::InorderTreeWalk(const Node* node, std::vector<int>& values)
{
    if (node == nullptr)
    {
        return;
    }
    InorderTreeWalk(node->left, values);
    values.push_back(node->value);
    InorderTreeWalk(node->right, values);
}

tree::Node* tree::BinarySearchTree::RecursiveTreeSearch(const int value)
{
    return RecursiveTreeSearch(root_, value);
}

tree::Node* tree::BinarySearchTree::RecursiveTreeSearch(Node* node, const int value)
{
    if ((node == nullptr) || value == node->value)
    {
        return node;
    }

    if (value < node->value)
    {
        return RecursiveTreeSearch(node->left, value);
    }
    else
    {
        return RecursiveTreeSearch(node->right, value);
    }
}

tree::Node* tree::BinarySearchTree::IterativeTreeSearch(const int value) const
{
    return IterativeTreeSearch(root_, value);
}

tree::Node* tree::BinarySearchTree::IterativeTreeSearch(Node* node, const int value)
{
    while ((node != nullptr) && (value != node->value))
    {
        if (value < node->value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return node;
}

tree::Node* tree::BinarySearchTree::GetMinimum() const
{
    return GetMinimum(root_);
}

tree::Node* tree::BinarySearchTree::GetMinimum(Node* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

tree::Node* tree::BinarySearchTree::GetMaximum() const
{
    return GetMaximum(root_);
}

tree::Node* tree::BinarySearchTree::GetMaximum(Node* node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

tree::Node* tree::BinarySearchTree::GetSuccessor(const int value) const
{
    const Node* node = IterativeTreeSearch(value);

    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->right != nullptr)
    {
        return GetMinimum(node->right);
    }

    Node* parent = node->parent;
    while ((parent != nullptr) && (node == parent->right))
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

tree::Node* tree::BinarySearchTree::GetPredecessor(const int value) const
{
    const Node* node = IterativeTreeSearch(value);

    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->left != nullptr)
    {
        return GetMaximum(node->left);
    }

    Node* parent = node->parent;
    while ((parent != nullptr) && (node == parent->left))
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}
