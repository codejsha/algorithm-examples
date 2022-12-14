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
        ExtendedNode* left;
        ExtendedNode* right;
        ExtendedNode* parent;

        ExtendedNode()
            : key{}, left{nullptr}, right{nullptr}, parent{nullptr}
        {
        }
        explicit ExtendedNode(T key)
            : key{key}, left{nullptr}, right{nullptr}, parent{nullptr}
        {
        }
        ExtendedNode(T key, ExtendedNode* left, ExtendedNode* right, ExtendedNode* parent)
            : key{key}, left{left}, right{right}, parent{parent}
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
