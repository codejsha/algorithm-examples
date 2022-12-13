#ifndef CPP_ALGORITHM_BINARY_TREE_H
#define CPP_ALGORITHM_BINARY_TREE_H

namespace BinaryTree
{
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
}

#endif
