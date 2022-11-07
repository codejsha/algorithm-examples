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
        void Insert(const int key) override;
        void Delete(const int key) override;

        [[nodiscard]] BinarySearchNode* TreeMinimum();
        [[nodiscard]] BinarySearchNode* TreeMaximum();
        [[nodiscard]] BinarySearchNode* TreePredecessor(const int key);
        [[nodiscard]] BinarySearchNode* TreeSuccessor(const int key);

        /// <summary>
        /// Recursive call to find a node
        /// </summary>
        /// <returns>found node</returns>
        [[nodiscard]] BinarySearchNode* RecursiveTreeSearch(const int key);

        /// <summary>
        /// Iterative call to find a node
        /// </summary>
        /// <returns>found node</returns>
        [[nodiscard]] BinarySearchNode* IterativeTreeSearch(const int key);

    protected:
        void Insert(BinarySearchNode*& ref, const int key) override;
        void Delete(BinarySearchNode*& ref, const int key) override;

        BinarySearchNode* TreeMinimum(BinarySearchNode* ref);
        BinarySearchNode* TreeMaximum(BinarySearchNode* ref);
        BinarySearchNode* TreePredecessor(BinarySearchNode* ref);
        BinarySearchNode* TreeSuccessor(BinarySearchNode* ref);

        /// <summary>
        /// Recursive call to find a node
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>found node</returns>
        BinarySearchNode* RecursiveTreeSearch(BinarySearchNode* ref, const int key);

        /// <summary>
        /// Iterative call to find a node
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>found node</returns>
        BinarySearchNode* IterativeTreeSearch(BinarySearchNode* ref, const int key);
    };
}

#endif
