#ifndef CPP_ALGORITHM_BINARY_TREE_H
#define CPP_ALGORITHM_BINARY_TREE_H

#include <vector>

namespace Tree
{
    /// <summary>
    /// Node of tree
    /// </summary>
    /// <typeparam name="T">type of node</typeparam>
    template <typename T>
    struct Node
    {
        int Key;
        T* Parent;
        std::vector<T*> Children{};

        explicit Node(const int key)
            : Key(key), Parent(nullptr)
        {
        }
    };

    /// <summary>
    /// Binary node of tree
    /// </summary>
    /// <typeparam name="T">type of node</typeparam>
    template <typename T>
    struct BinaryNode : Node<T>
    {
        T* Left;
        T* Right;

        explicit BinaryNode(const int key)
            : Node<T>(key), Left(nullptr), Right(nullptr)
        {
        }
    };

    /// <summary>
    /// Tree
    /// </summary>
    /// <typeparam name="T">type of node</typeparam>
    template <typename T>
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

        virtual void Insert(const int key) = 0;
        virtual void Insert(T* v) = 0;
        virtual void Delete(const int key) = 0;
        virtual void Delete(T* v) = 0;

    protected:
        virtual void Insert(T*& t, const int key) = 0;
        virtual void Insert(T*& t, T* v) = 0;
        virtual void Delete(T*& t, const int key) = 0;
        virtual void Delete(T*& t, T* v) = 0;
    };

    /// <summary>
    /// Binary tree
    /// </summary>
    /// <typeparam name="T">type of node</typeparam>
    template <typename T>
    class BinaryTree : Tree<T>
    {
    public:
        [[nodiscard]] auto GetRoot() const -> T*
        {
            return Root;
        }

        [[nodiscard]] auto GetNodes() const -> std::vector<T*>
        {
            return Nodes;
        }

        /// <summary>
        /// Preorder traversal of tree
        /// </summary>
        /// <returns>traversal result</returns>
        auto PreorderTreeWalk() -> std::vector<int>
        {
            auto keys = std::vector<int>();
            PreorderTreeWalk(Root, keys);
            return keys;
        }

        /// <summary>
        /// Inorder traversal of tree
        /// </summary>
        /// <returns>traversal result</returns>
        auto InorderTreeWalk() -> std::vector<int>
        {
            auto keys = std::vector<int>();
            InorderTreeWalk(Root, keys);
            return keys;
        }

        /// <summary>
        /// Postorder traversal of tree
        /// </summary>
        /// <returns>traversal result</returns>
        auto PostorderTreeWalk() -> std::vector<int>
        {
            auto keys = std::vector<int>();
            PostorderTreeWalk(Root, keys);
            return keys;
        }

        /// <summary>
        /// Check if tree is balanced
        /// </summary>
        /// <returns>whether full binary tree or not</returns>
        auto IsFullBinaryTree() -> bool
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
        auto PreorderTreeWalk(const T* node, std::vector<int>& keys) -> void
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
        auto InorderTreeWalk(const T* node, std::vector<int>& keys) -> void
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
        auto PostorderTreeWalk(const T* node, std::vector<int>& keys) -> void
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
        auto IsFullBinaryTree(const T* node) -> bool
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
} // namespace Tree

#endif
