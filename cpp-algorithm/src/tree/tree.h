#ifndef CPP_ALGORITHM_BINARY_TREE_H
#define CPP_ALGORITHM_BINARY_TREE_H

#include <vector>

namespace Tree
{
    /// @brief Node of tree
    /// @tparam T1 type of node
    /// @tparam T2 type of key
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

    /// @brief Binary node of tree
    /// @tparam T type of node
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

    /// @brief Tree
    /// @tparam T1 type of node
    /// @tparam T2 type of key
    template <typename T1, typename T2>
    class Tree
    {
    public:
        Tree() = default;

        Tree(const Tree& other) = default;

        Tree(Tree&& other) noexcept = default;

        auto operator=(const Tree& other) -> Tree&
        {
            if (this == &other)
                return *this;
            return *this;
        }

        auto operator=(Tree&& other) noexcept -> Tree&
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

    /// @brief Binary tree
    /// @tparam T type of node
    template <typename T>
    class BinaryTree : Tree<T, int>
    {
    public:
        [[nodiscard]] auto
        GetRoot() const -> T*
        {
            return Root;
        }

        [[nodiscard]] auto GetNodes() const -> std::vector<T*>
        {
            return Nodes;
        }

        /// @brief Preorder traversal of tree
        /// @return traversal result
        auto PreorderTreeWalk() -> std::vector<int>
        {
            auto keys = std::vector<int>();
            PreorderTreeWalk(Root, keys);
            return keys;
        }

        /// @brief Inorder traversal of tree
        /// @return traversal result
        auto InorderTreeWalk() -> std::vector<int>
        {
            auto keys = std::vector<int>();
            InorderTreeWalk(Root, keys);
            return keys;
        }

        /// @brief Postorder traversal of tree
        /// @return traversal result
        auto PostorderTreeWalk() -> std::vector<int>
        {
            auto keys = std::vector<int>();
            PostorderTreeWalk(Root, keys);
            return keys;
        }

        /// @brief Check if tree is balanced
        /// @return whether full binary tree or not
        auto IsFullBinaryTree() -> bool
        {
            return IsFullBinaryTree(Root);
        }

    protected:
        T* Root{};
        std::vector<T*> Nodes{};

        /// @brief Preorder traversal of tree
        /// @param node reference node for tree traversal
        /// @param keys keys of tree
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

        /// @brief Inorder traversal of tree
        /// @param node reference node for tree traversal
        /// @param keys keys of tree
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

        /// @brief Postorder traversal of tree
        /// @param node reference node for tree traversal
        /// @param keys keys of tree
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

        /// @brief Check if tree is balanced
        /// @param node reference node for tree traversal
        /// @return whether full binary tree or not
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
}

#endif
