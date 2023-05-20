#ifndef CPP_ALGORITHM_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHM_BINARY_SEARCH_TREE_H

#include "binary_tree.h"

#include <vector>

namespace BinarySearchTree
{
    template <typename T>
    class Tree
    {
    public:
        Tree() = default;

        [[nodiscard]] auto GetRoot() const -> BinaryTree::ExtendedNode<T>* { return root_; }

        void Insert(T key);
        auto Delete(BinaryTree::ExtendedNode<T>* current, T key) -> BinaryTree::ExtendedNode<T>*;

        static auto Minimum(BinaryTree::ExtendedNode<T>* node) -> BinaryTree::ExtendedNode<T>*;
        static auto Maximum(BinaryTree::ExtendedNode<T>* node) -> BinaryTree::ExtendedNode<T>*;

        auto Predecessor(T key) -> BinaryTree::ExtendedNode<T>*;
        auto Successor(T key) -> BinaryTree::ExtendedNode<T>*;

        /// @brief Recursive call to find the node
        /// @param node reference node
        /// @param key key to search for
        /// @return found node
        auto IterativeSearch(BinaryTree::ExtendedNode<T>* node, T key) -> BinaryTree::ExtendedNode<T>*;

        /// @brief Iterative call to find a node
        /// @param node reference node
        /// @param key key to search for
        /// @return found node
        auto RecursiveSearch(BinaryTree::ExtendedNode<T>* node, T key) -> BinaryTree::ExtendedNode<T>*;

        void PreorderTraversal(BinaryTree::ExtendedNode<T>* node, std::vector<T>& result);
        void InorderTraversal(BinaryTree::ExtendedNode<T>* node, std::vector<T>& result);
        void PostorderTraversal(BinaryTree::ExtendedNode<T>* node, std::vector<T>& result);

    private:
        BinaryTree::ExtendedNode<T>* root_;
    };

    template <typename T>
    void Tree<T>::Insert(T key)
    {
        auto* node = new BinaryTree::ExtendedNode<T>();
        node->key = key;
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;

        if (root_ == nullptr)
        {
            root_ = node;
        }
        else
        {
            BinaryTree::ExtendedNode<T>* current = root_;
            while (true)
            {
                if (key < current->key)
                {
                    if (current->left == nullptr)
                    {
                        current->left = node;
                        node->parent = current;
                        break;
                    }
                    current = current->left;
                }
                else
                {
                    if (current->right == nullptr)
                    {
                        current->right = node;
                        node->parent = current;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    template <typename T>
    auto Tree<T>::Delete(BinaryTree::ExtendedNode<T>* current, T key) -> BinaryTree::ExtendedNode<T>*
    {
        if (current == nullptr)
        {
            return current;
        }

        if (key < current->key)
        {
            current->left = Delete(current->left, key);
            if (current->left != nullptr)
            {
                current->left->parent = current;
            }
        }
        else if (key > current->key)
        {
            current->right = Delete(current->right, key);
            if (current->right != nullptr)
            {
                current->right->parent = current;
            }
        }
        else
        {
            if (current->left == nullptr)
            {
                auto* temp = current->right;
                return temp;
            }
            if (current->right == nullptr)
            {
                auto* temp = current->left;
                return temp;
            }

            auto temp = Minimum(current->right);
            current->key = temp->key;
            current->right = Delete(current->right, temp->key);
        }
        return current;
    }

    template <typename T>
    auto Tree<T>::Minimum(BinaryTree::ExtendedNode<T>* node) -> BinaryTree::ExtendedNode<T>*
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    template <typename T>
    auto Tree<T>::Maximum(BinaryTree::ExtendedNode<T>* node) -> BinaryTree::ExtendedNode<T>*
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    template <typename T>
    auto Tree<T>::Predecessor(T key) -> BinaryTree::ExtendedNode<T>*
    {
        auto node = IterativeSearch(root_, key);

        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->left != nullptr)
        {
            return Maximum(node->left);
        }

        auto parent = node->parent;
        while ((parent != nullptr) && (node == parent->left))
        {
            node = parent;
            parent = parent->parent;
        }

        return parent;
    }

    template <typename T>
    auto Tree<T>::Successor(T key) -> BinaryTree::ExtendedNode<T>*
    {
        auto node = IterativeSearch(root_, key);

        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->right != nullptr)
        {
            return Minimum(node->right);
        }

        auto parent = node->parent;
        while ((parent != nullptr) && (node == parent->right))
        {
            node = parent;
            parent = parent->parent;
        }

        return parent;
    }

    template <typename T>
    auto Tree<T>::IterativeSearch(BinaryTree::ExtendedNode<T>* node, T key) -> BinaryTree::ExtendedNode<T>*
    {
        while ((node != nullptr) && (key != node->key))
        {
            if (key < node->key)
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

    template <typename T>
    auto Tree<T>::RecursiveSearch(BinaryTree::ExtendedNode<T>* node, T key) -> BinaryTree::ExtendedNode<T>*
    {
        if ((node == nullptr) || key == node->key)
        {
            return node;
        }

        if (key < node->key)
        {
            return RecursiveSearch(node->left, key);
        }
        return RecursiveSearch(node->right, key);
    }

    template <typename T>
    void Tree<T>::PreorderTraversal(BinaryTree::ExtendedNode<T>* node, std::vector<T>& result)
    {
        if (node == nullptr)
        {
            return;
        }

        result.push_back(node->key);
        PreorderTraversal(node->left, result);
        PreorderTraversal(node->right, result);
    }

    template <typename T>
    void Tree<T>::InorderTraversal(BinaryTree::ExtendedNode<T>* node, std::vector<T>& result)
    {
        if (node == nullptr)
        {
            return;
        }

        InorderTraversal(node->left, result);
        result.push_back(node->key);
        InorderTraversal(node->right, result);
    }

    template <typename T>
    void Tree<T>::PostorderTraversal(BinaryTree::ExtendedNode<T>* node, std::vector<T>& result)
    {
        if (node == nullptr)
        {
            return;
        }

        PostorderTraversal(node->left, result);
        PostorderTraversal(node->right, result);
        result.push_back(node->key);
    }
}

#endif
