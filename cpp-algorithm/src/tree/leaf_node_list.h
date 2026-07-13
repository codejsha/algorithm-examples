#ifndef CPP_ALGORITHM_LEAF_NODE_LIST_H
#define CPP_ALGORITHM_LEAF_NODE_LIST_H

#include "binary_tree.h"

#include <vector>

namespace LeafNodeList
{
    /**
     * \brief Create a list of leaf nodes.
     * \param root the root of the tree
     * \return leaf node list
     */
    std::vector<BinaryTree::Node<int>*> CreateLeafNodeList(
        BinaryTree::Node<int>* root);
}

// ----------------------------------------------------------------------------
/**
 * \brief Add leaf nodes to the list.
 * \param root the root of the tree
 * \param leaf_node_list leaf node list
 */
inline void AddLeafNodeToList(
    BinaryTree::Node<int>* root,
    std::vector<BinaryTree::Node<int>*>& leaf_node_list)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        leaf_node_list.push_back(root);
        return;
    }
    AddLeafNodeToList(root->left, leaf_node_list);
    AddLeafNodeToList(root->right, leaf_node_list);
}

// ----------------------------------------------------------------------------
inline std::vector<BinaryTree::Node<int>*> LeafNodeList::CreateLeafNodeList(
    BinaryTree::Node<int>* root)
{
    auto leaf_node_list = std::vector<BinaryTree::Node<int>*>{};
    AddLeafNodeToList(root, leaf_node_list);
    return leaf_node_list;
}

#endif
