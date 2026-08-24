#ifndef CPP_ALGORITHM_BINARY_TREE_EXTERIOR_H
#define CPP_ALGORITHM_BINARY_TREE_EXTERIOR_H

#include "binary_tree.h"

#include <vector>

namespace BinaryTreeExterior
{
    /**
     * \brief Create a list of exterior nodes.
     * \param root the root of the tree
     * \return exterior node list
     */
    std::vector<BinaryTree::Node<char>*> CreateExteriorNodeList(
        BinaryTree::Node<char>* root);
}

// ----------------------------------------------------------------------------
/**
 * \brief Create a list of left exterior nodes.
 * \param root the root node of the subtree
 * \param exterior_nodes left exterior nodes
 */
inline void CreateLeftBoundary(
    BinaryTree::Node<char>* root,
    std::vector<BinaryTree::Node<char>*>& exterior_nodes)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    exterior_nodes.push_back(root);
    if (root->left != nullptr)
    {
        CreateLeftBoundary(root->left, exterior_nodes);
    }
    else
    {
        CreateLeftBoundary(root->right, exterior_nodes);
    }
}

// ----------------------------------------------------------------------------
/**
 * \brief Create a list of right exterior nodes.
 * \param root the root node of the subtree
 * \param exterior_nodes right exterior nodes
 */
inline void CreateRightBoundary(
    BinaryTree::Node<char>* root,
    std::vector<BinaryTree::Node<char>*>& exterior_nodes)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    exterior_nodes.push_back(root);
    if (root->right != nullptr)
    {
        CreateRightBoundary(root->right, exterior_nodes);
    }
    else
    {
        CreateRightBoundary(root->left, exterior_nodes);
    }
}

// ----------------------------------------------------------------------------
/**
 * \brief Create a list of leaf exterior nodes.
 * \param root the root node of the subtree
 * \param exterior_nodes leaf exterior nodes
 */
inline void CreateLeafBoundary(
    BinaryTree::Node<char>* root,
    std::vector<BinaryTree::Node<char>*>& exterior_nodes)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        exterior_nodes.push_back(root);
        return;
    }
    CreateLeafBoundary(root->left, exterior_nodes);
    CreateLeafBoundary(root->right, exterior_nodes);
}

// ----------------------------------------------------------------------------
inline std::vector<BinaryTree::Node<char>*> BinaryTreeExterior::CreateExteriorNodeList(
    BinaryTree::Node<char>* root)
{
    auto exterior_node_list = std::vector<BinaryTree::Node<char>*>();
    if (root == nullptr)
    {
        return exterior_node_list;
    }

    exterior_node_list.push_back(root);
    CreateLeftBoundary(root->left, exterior_node_list);
    CreateLeafBoundary(root, exterior_node_list);
    CreateRightBoundary(root->right, exterior_node_list);

    return exterior_node_list;
}

#endif
