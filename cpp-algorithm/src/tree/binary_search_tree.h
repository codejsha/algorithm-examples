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
        void Insert(int key) override;
        void Delete(int key) override;

        [[nodiscard]] BinarySearchNode* TreeMinimum();
        [[nodiscard]] BinarySearchNode* TreeMaximum();
        [[nodiscard]] BinarySearchNode* TreePredecessor(int key);
        [[nodiscard]] BinarySearchNode* TreeSuccessor(int key);

        /// <summary>
        /// Recursive call to find a node
        /// </summary>
        /// <returns>found node</returns>
        [[nodiscard]] BinarySearchNode* RecursiveTreeSearch(int key);

        /// <summary>
        /// Iterative call to find a node
        /// </summary>
        /// <returns>found node</returns>
        [[nodiscard]] BinarySearchNode* IterativeTreeSearch(int key);

    protected:
        void Insert(BinarySearchNode*& ref, int key) override;
        void Delete(BinarySearchNode*& ref, int key) override;

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
        BinarySearchNode* RecursiveTreeSearch(BinarySearchNode* ref, int key);

        /// <summary>
        /// Iterative call to find a node
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>found node</returns>
        BinarySearchNode* IterativeTreeSearch(BinarySearchNode* ref, int key);
    };
}

#endif
