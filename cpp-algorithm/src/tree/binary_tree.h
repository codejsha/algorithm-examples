#ifndef CPP_ALGORITHM_BINARY_TREE_H
#define CPP_ALGORITHM_BINARY_TREE_H

namespace BinaryTree
{
    /// @brief Binary tree node.
    /// @tparam T the type of the key
    template <typename T>
    struct Node
    {
        T key;
        Node* left;
        Node* right;
        Node()
            : key{}, left{nullptr}, right{nullptr}
        {
        }
        explicit Node(T key)
            : key{key}, left{nullptr}, right{nullptr}
        {
        }
        Node(T key, Node* left, Node* right)
            : key{key}, left{left}, right{right}
        {
        }
    };

    /// @brief Extended binary tree node with parent pointer.
    /// @tparam T the type of the key
    template <typename T>
    struct ExtendedNode
    {
        T key;
        ExtendedNode* parent;
        ExtendedNode* left;
        ExtendedNode* right;

        ExtendedNode()
            : key{}, parent{nullptr}, left{nullptr}, right{nullptr}
        {
        }
        explicit ExtendedNode(T key)
            : key{key}, parent{nullptr}, left{nullptr}, right{nullptr}
        {
        }
        ExtendedNode(T key, ExtendedNode* parent, ExtendedNode* left, ExtendedNode* right)
            : key{key}, parent{parent}, left{left}, right{right}
        {
        }
    };

    /// @brief Extended binary tree node with next pointer.
    /// @tparam T the type of the key
    template <typename T>
    struct NextExtendedNode
    {
        T key;
        NextExtendedNode* left;
        NextExtendedNode* right;
        NextExtendedNode* next;

        NextExtendedNode()
            : key{}, left{nullptr}, right{nullptr}, next{nullptr}
        {
        }
        explicit NextExtendedNode(T key)
            : key{key}, left{nullptr}, right{nullptr}, next{nullptr}
        {
        }
        NextExtendedNode(T key, NextExtendedNode* left, NextExtendedNode* right, NextExtendedNode* next)
            : key{key}, left{left}, right{right}, next{nullptr}
        {
        }
    };

    /// @brief Get the height of a binary tree.
    /// @tparam T the type of the key
    /// @param node the root of the tree
    /// @return the height of the tree
    template <typename T> auto ExtendedNodeTreeDepth(const ExtendedNode<T>* node) -> int
    {
        auto depth = 0;
        while (node->parent)
        {
            ++depth;
            node = node->parent;
        }
        return depth;
    }
}

#endif
