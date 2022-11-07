#ifndef CPP_ALGORITHM_BINARY_TREE_H
#define CPP_ALGORITHM_BINARY_TREE_H

#include <vector>

namespace Tree
{
    /// <summary>
    /// Node of tree
    /// </summary>
    /// <typeparam name="T1">type of node</typeparam>
    /// <typeparam name="T2">type of key</typeparam>
    template <typename T1, typename T2>
    struct Node
    {
        T2 Key;
        T1* Parent;
        std::vector<T1*> Children{};

        explicit Node(T2 k)
            : Key(k), Parent(nullptr)
        {
        }
    };

    /// <summary>
    /// Binary node of tree
    /// </summary>
    /// <typeparam name="T">type of node</typeparam>
    template <typename T>
    struct BinaryNode : Node<T, int>
    {
        T* Left;
        T* Right;

        explicit BinaryNode(const int key)
            : Node<T, int>(key), Left(nullptr), Right(nullptr)
        {
        }
    };

    /// <summary>
    /// Tree
    /// </summary>
    /// <typeparam name="T1">type of node</typeparam>
    /// <typeparam name="T2">type of key</typeparam>
    template <typename T1, typename T2>
    class Tree
    {
    public:
        Tree() = default;

        Tree(const Tree& other) = default;

        Tree(Tree&& other) noexcept = default;

        Tree& operator=(const Tree& other)
        {
            if (this == &other)
                return *this;
            return *this;
        }

        Tree& operator=(Tree&& other) noexcept
        {
            if (this == &other)
                return *this;
            return *this;
        }

        virtual void Insert(T2 k) = 0;
        virtual void Delete(T2 k) = 0;

    protected:
        virtual void Insert(T1*& t, T2 k) = 0;
        virtual void Delete(T1*& t, T2 k) = 0;
    };

    /// <summary>
    /// Binary tree
    /// </summary>
    /// <typeparam name="T">type of node</typeparam>
    template <typename T>
    class BinaryTree : Tree<T, int>
    {
    public:
        [[nodiscard]] T*
        GetRoot() const
        {
            return Root;
        }

        [[nodiscard]] std::vector<T*> GetNodes() const
        {
            return Nodes;
        }

        /// <summary>
        /// Preorder traversal of tree
        /// </summary>
        /// <returns>traversal result</returns>
        std::vector<int> PreorderTreeWalk()
        {
            auto keys = std::vector<int>();
            PreorderTreeWalk(Root, keys);
            return keys;
        }

        /// <summary>
        /// Inorder traversal of tree
        /// </summary>
        /// <returns>traversal result</returns>
        std::vector<int> InorderTreeWalk()
        {
            auto keys = std::vector<int>();
            InorderTreeWalk(Root, keys);
            return keys;
        }

        /// <summary>
        /// Postorder traversal of tree
        /// </summary>
        /// <returns>traversal result</returns>
        std::vector<int> PostorderTreeWalk()
        {
            auto keys = std::vector<int>();
            PostorderTreeWalk(Root, keys);
            return keys;
        }

        /// <summary>
        /// Check if tree is balanced
        /// </summary>
        /// <returns>whether full binary tree or not</returns>
        bool IsFullBinaryTree()
        {
            return IsFullBinaryTree(Root);
        }

    protected:
        T* Root{};
        std::vector<T*> Nodes{};

        /// <summary>
        /// Preorder traversal of tree
        /// </summary>
        /// <param name="node">reference node for tree traversal</param>
        /// <param name="keys">keys of tree</param>
        void PreorderTreeWalk(const T* node, std::vector<int>& keys)
        {
            if (node == nullptr)
            {
                return;
            }
            keys.push_back(node->Key);
            PreorderTreeWalk(node->Left, keys);
            PreorderTreeWalk(node->Right, keys);
        }

        /// <summary>
        /// Inorder traversal of tree
        /// </summary>
        /// <param name="node">reference node for tree traversal</param>
        /// <param name="keys">keys of tree</param>
        void InorderTreeWalk(const T* node, std::vector<int>& keys)
        {
            if (node == nullptr)
            {
                return;
            }
            InorderTreeWalk(node->Left, keys);
            keys.push_back(node->Key);
            InorderTreeWalk(node->Right, keys);
        }

        /// <summary>
        /// Postorder traversal of tree
        /// </summary>
        /// <param name="node">reference node for tree traversal</param>
        /// <param name="keys">keys of tree</param>
        void PostorderTreeWalk(const T* node, std::vector<int>& keys)
        {
            if (node == nullptr)
            {
                return;
            }
            PostorderTreeWalk(node->Left, keys);
            PostorderTreeWalk(node->Right, keys);
            keys.push_back(node->Key);
        }

        /// <summary>
        /// Check if tree is balanced
        /// </summary>
        /// <param name="node">reference node for tree traversal</param>
        /// <returns>whether full binary tree or not</returns>
        bool IsFullBinaryTree(const T* node)
        {
            if (Root == nullptr)
            {
                return true;
            }
            else if ((node->Left == nullptr) && (node->Right == nullptr))
            {
                return true;
            }
            else if ((node->Left != nullptr) && (node->Right != nullptr))
            {
                return IsFullBinaryTree(node->Left) && IsFullBinaryTree(node->Right);
            }
            else
            {
                return false;
            }
        }
    };
}

#endif
