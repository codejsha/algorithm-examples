#ifndef CPP_ALGORITHM_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHM_BINARY_SEARCH_TREE_H

#include "tree.h"

namespace Tree
{
    /// <summary>
    /// Node of binary search tree
    /// </summary>
    struct BinarySearchNode : BinaryNode<BinarySearchNode>
    {
        explicit BinarySearchNode(const int key)
            : BinaryNode<BinarySearchNode>(key)
        {
        }
    };

    /// <summary>
    /// Binary search tree
    /// </summary>
    class BinarySearchTree : public BinaryTree<BinarySearchNode>
    {
    public:
        auto Insert(const int key) -> void override;
        auto Insert(BinarySearchNode* node) -> void override
        {
        }
        auto Delete(const int key) -> void override;
        auto Delete(BinarySearchNode* node) -> void override
        {
        }

        [[nodiscard]] auto TreeMinimum() -> BinarySearchNode*;
        [[nodiscard]] auto TreeMaximum() -> BinarySearchNode*;
        [[nodiscard]] auto TreePredecessor(const int key) -> BinarySearchNode*;
        [[nodiscard]] auto TreeSuccessor(const int key) -> BinarySearchNode*;

        /// <summary>
        /// Recursive call to find a node
        /// </summary>
        /// <returns>found node</returns>
        [[nodiscard]] auto RecursiveTreeSearch(const int key) -> BinarySearchNode*;

        /// <summary>
        /// Iterative call to find a node
        /// </summary>
        /// <returns>found node</returns>
        [[nodiscard]] auto IterativeTreeSearch(const int key) -> BinarySearchNode*;

    protected:
        auto Insert(BinarySearchNode*& ref, const int key) -> void override;
        auto Insert(BinarySearchNode*& ref, BinarySearchNode* node) -> void override
        {
        }
        auto Delete(BinarySearchNode*& ref, const int key) -> void override;
        auto Delete(BinarySearchNode*& ref, BinarySearchNode* node) -> void override
        {
        }

        auto TreeMinimum(BinarySearchNode* ref) -> BinarySearchNode*;
        auto TreeMaximum(BinarySearchNode* ref) -> BinarySearchNode*;
        auto TreePredecessor(BinarySearchNode* ref) -> BinarySearchNode*;
        auto TreeSuccessor(BinarySearchNode* ref) -> BinarySearchNode*;

        /// <summary>
        /// Recursive call to find a node
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>found node</returns>
        auto RecursiveTreeSearch(BinarySearchNode* ref, const int key) -> BinarySearchNode*;

        /// <summary>
        /// Iterative call to find a node
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>found node</returns>
        auto IterativeTreeSearch(BinarySearchNode* ref, const int key) -> BinarySearchNode*;
    };
} // namespace Tree

#endif
