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
    };
}

#endif
