#ifndef CPP_ALGORITHM_BINARY_SEARCH_TREE_H
#define CPP_ALGORITHM_BINARY_SEARCH_TREE_H

#include <vector>

namespace tree
{
    struct Node
    {
        int value;
        Node* left;
        Node* right;
        Node* parent;

        explicit Node(int value)
            : value(value), left(nullptr), right(nullptr), parent(nullptr)
        {
        }
    };

    class BinarySearchTree
    {
    public:
        void Insert(int value);
        void Delete(int value);

        Node* GetMinimum() const;
        Node* GetMaximum() const;
        Node* GetSuccessor(int value) const;
        Node* GetPredecessor(int value) const;

        std::vector<int> InorderTreeWalk();
        Node* RecursiveTreeSearch(int value);
        Node* IterativeTreeSearch(int value) const;

    private:
        Node* root_{};

        void Insert(Node*& node, int value);
        void Delete(Node*& node, int value);

        static Node* GetMinimum(Node* node);
        static Node* GetMaximum(Node* node);

        void InorderTreeWalk(const Node* node, std::vector<int>& values);
        Node* RecursiveTreeSearch(Node* node, int value);
        static Node* IterativeTreeSearch(Node* node, int value);
    };
} // namespace tree

#endif
