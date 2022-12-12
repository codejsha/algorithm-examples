#ifndef CPP_ALGORITHM_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHM_BINARY_SEARCH_TREE_H

#include <vector>

namespace BinarySearchTree
{
    template <typename T>
    struct Node
    {
        T key;
        Node* parent;
        Node* left;
        Node* right;
    };

    template <typename T>
    class Tree
    {
    public:
        explicit Tree()
            : root_(nullptr)
        {
        }

        [[nodiscard]] auto GetRoot() const -> Node<T>*
        {
            return root_;
        }

        void Insert(T key);
        auto Delete(Node<T>* current, T key) -> Node<T>*;

        static auto Minimum(Node<T>* node) -> Node<T>*;
        static auto Maximum(Node<T>* node) -> Node<T>*;

        auto Predecessor(T key) -> Node<T>*;
        auto Successor(T key) -> Node<T>*;

        /// @brief Recursive call to find the node
        /// @param node reference node
        /// @param key key to search for
        /// @return found node
        auto IterativeSearch(Node<T>* node, T key) -> Node<T>*;

        /// @brief Iterative call to find a node
        /// @param node reference node
        /// @param key key to search for
        /// @return found node
        auto RecursiveSearch(Node<T>* node, T key) -> Node<T>*;

        void PreorderTraversal(Node<T>* node, std::vector<T>& result);
        void InorderTraversal(Node<T>* node, std::vector<T>& result);
        void PostorderTraversal(Node<T>* node, std::vector<T>& result);

    private:
        Node<T>* root_;
    };

    template <typename T> void Tree<T>::Insert(T key)
    {
        auto* node = new Node<T>();
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
            Node<T>* current = root_;
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
                    else
                    {
                        current = current->left;
                    }
                }
                else
                {
                    if (current->right == nullptr)
                    {
                        current->right = node;
                        node->parent = current;
                        break;
                    }
                    else
                    {
                        current = current->right;
                    }
                }
            }
        }
    }

    template <typename T> auto Tree<T>::Delete(Node<T>* current, T key) -> Node<T>*
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

    template <typename T> auto Tree<T>::Minimum(Node<T>* node) -> Node<T>*
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    template <typename T> auto Tree<T>::Maximum(Node<T>* node) -> Node<T>*
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    template <typename T> auto Tree<T>::Predecessor(T key) -> Node<T>*
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

    template <typename T> auto Tree<T>::Successor(T key) -> Node<T>*
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

    template <typename T> auto Tree<T>::IterativeSearch(Node<T>* node, T key) -> Node<T>*
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

    template <typename T> auto Tree<T>::RecursiveSearch(Node<T>* node, T key) -> Node<T>*
    {
        if ((node == nullptr) || key == node->key)
        {
            return node;
        }

        if (key < node->key)
        {
            return RecursiveSearch(node->left, key);
        }
        else
        {
            return RecursiveSearch(node->right, key);
        }
    }

    template <typename T> void Tree<T>::PreorderTraversal(Node<T>* node, std::vector<T>& result)
    {
        if (node == nullptr)
        {
            return;
        }

        result.push_back(node->key);
        PreorderTraversal(node->left, result);
        PreorderTraversal(node->right, result);
    }

    template <typename T> void Tree<T>::InorderTraversal(Node<T>* node, std::vector<T>& result)
    {
        if (node == nullptr)
        {
            return;
        }

        InorderTraversal(node->left, result);
        result.push_back(node->key);
        InorderTraversal(node->right, result);
    }

    template <typename T> void Tree<T>::PostorderTraversal(Node<T>* node, std::vector<T>& result)
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
