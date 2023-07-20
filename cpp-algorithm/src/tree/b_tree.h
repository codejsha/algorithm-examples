#ifndef CPP_ALGORITHM_B_TREE_H
#define CPP_ALGORITHM_B_TREE_H

#include <vector>

namespace BTree
{
    struct Node
    {
        std::vector<char> keys;
        std::vector<Node*> children;
        bool is_leaf;
    };

    class Tree
    {
    public:
        Node* root;
        std::vector<Node*> nodes;
        int degree;

        /**
         * \brief Split the node
         * \param node internal node
         * \param index index
         */
        void SplitChild(Node* node, int index);

        /**
         * \brief Insert key
         * \param node internal node
         * \param key key
         */
        void InsertNonFull(Node* node, char key);

        /**
         * \brief Insert the key to the tree
         * \param node reference node for insert
         * \param key key to insert
         */
        void Insert(Node* node, char key);

        /**
         * \brief Search the key
         * \param node reference node for tree search
         * \param key key to search for
         * \return node and key index pair
         */
        auto Search(Node* node, char key) -> std::pair<Node*, const int>;
    };
}

#endif
