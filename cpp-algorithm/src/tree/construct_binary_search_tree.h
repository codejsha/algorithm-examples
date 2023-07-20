#ifndef CPP_ALGORITHM_CONSTRUCT_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHM_CONSTRUCT_BINARY_SEARCH_TREE_H

#include "binary_tree.h"

#include <unordered_map>
#include <vector>

namespace ConstructBinarySearchTree
{
    /**
     * \brief Construct the subtree from the given preorder and inorder traversal.
     * This is a helper function for ConstructTreeFromPreorderInorder.
     * \note In this operation, the parent pointer of struct Node is ignored.
     * \tparam T the type of the key
     * \param preorder preorder traversal result
     * \param inorder inorder traversal result
     * \param preorder_start start index of preorder map
     * \param preorder_end end index of preorder map
     * \param inorder_start start index of inorder map
     * \param inorder_end end index of inorder map
     * \param inorder_map inorder hash table
     * \return the root of the subtree
     */
    template <typename T>
    auto ConstructTreeFromPreorderInorderHelper(std::vector<T>& preorder, std::vector<T>& inorder, int preorder_start,
                                                int preorder_end, int inorder_start, int inorder_end,
                                                std::unordered_map<T, int>& inorder_map) -> BinaryTree::ExtendedNode<T>*
    {
        if (preorder_start > preorder_end || inorder_start > inorder_end)
        {
            return nullptr;
        }
        auto root = new BinaryTree::ExtendedNode<T>{};
        root->key = preorder.at(preorder_start);

        auto inorder_root_idx = inorder_map.at(root->key);
        auto left_tree_size = inorder_root_idx - inorder_start;
        root->left = ConstructTreeFromPreorderInorderHelper(preorder, inorder, preorder_start + 1,
                                                            preorder_start + left_tree_size, inorder_start,
                                                            inorder_root_idx - 1, inorder_map);
        root->right =
            ConstructTreeFromPreorderInorderHelper(preorder, inorder, preorder_start + left_tree_size + 1, preorder_end,
                                                   inorder_root_idx + 1, inorder_end, inorder_map);
        return root;
    }

    /**
     * \brief Construct a binary search tree from preorder and inorder traversal.
     * \details The preorder traversal is the root node, then the left subtree, then the right subtree.
     * The inorder traversal is the left subtree, then the root node, then the right subtree.
     * The time complexity is O(n). It takes O(n) to create the hash table and O(1) for each node in recursion.
     * When the height is h, the space complexity is O(n+h) = O(n).
     * \note In this operation, the parent pointer of struct Node is ignored.
     * \tparam T the type of the key
     * \param preorder preorder traversal result
     * \param inorder inorder traversal result
     * \return the root of the constructed tree
     */
    template <typename T>
    auto ConstructTreeFromPreorderInorder(std::vector<T>& preorder, std::vector<T>& inorder)
        -> BinaryTree::ExtendedNode<T>*
    {
        auto inorder_map = std::unordered_map<T, int>();
        for (auto i = 0; i < inorder.size(); ++i)
        {
            inorder_map.emplace(inorder[i], i);
        }
        return ConstructTreeFromPreorderInorderHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1,
                                                      inorder_map);
    }

    /**
     * \brief Construct the subtree from the given postorder traversal with marker.
     * This is a helper function for ConstructTreeFromPreorderInorder.
     * \note In this operation, the parent pointer of struct Node is ignored.
     * \tparam T the type of the key
     * \param preorder preorder traversal result
     * \param subtree_idx_pointer subtree index pointer
     * \return the root of the subtree
     */
    template <typename T>
    auto ConstructTreeFromMarkerPreorderHelper(std::vector<T>& preorder, int& subtree_idx_pointer)
        -> BinaryTree::ExtendedNode<T>*
    {
        if (subtree_idx_pointer >= preorder.size())
        {
            return nullptr;
        }

        auto subtree_root = preorder[subtree_idx_pointer];
        if (subtree_root == NULL)
        {
            return nullptr;
        }

        auto root = new BinaryTree::ExtendedNode<T>{};
        root->key = subtree_root;
        ++subtree_idx_pointer;
        root->left = ConstructTreeFromMarkerPreorderHelper(preorder, subtree_idx_pointer);
        ++subtree_idx_pointer;
        root->right = ConstructTreeFromMarkerPreorderHelper(preorder, subtree_idx_pointer);

        return root;
    }

    /**
     * \brief Construct a binary search tree from preorder traversal with marker.
     * \details When the count of nodes is n, the time complexity is O(n).
     * \note In this operation, the parent pointer of struct Node is ignored.
     * \tparam T the type of the key
     * \param preorder preorder traversal result
     * \return the root of the constructed tree
     */
    template <typename T>
    auto ConstructTreeFromMarkerPreorder(std::vector<T>& preorder) -> BinaryTree::ExtendedNode<T>*
    {
        auto subtree_idx_pointer = 0;
        return ConstructTreeFromMarkerPreorderHelper(preorder, subtree_idx_pointer);
    }
}

#endif
