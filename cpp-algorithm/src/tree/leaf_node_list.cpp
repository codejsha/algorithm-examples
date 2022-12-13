#include "leaf_node_list.h"

/// @brief Add leaf nodes to the list.
/// @param root the root of the tree
/// @param leaf_node_list leaf node list
void AddLeafNodeToList(BinaryTree::Node<int>* root, std::vector<BinaryTree::Node<int>*>& leaf_node_list)
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

auto LeafNodeList::CreateLeafNodeList(BinaryTree::Node<int>* root) -> std::vector<BinaryTree::Node<int>*>
{
    auto leaf_node_list = std::vector<BinaryTree::Node<int>*>{};
    AddLeafNodeToList(root, leaf_node_list);
    return leaf_node_list;
}
