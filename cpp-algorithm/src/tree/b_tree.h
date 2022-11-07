#ifndef CPP_ALGORITHM_B_TREE_H
#define CPP_ALGORITHM_B_TREE_H

#include <vector>

namespace Tree
{
    struct BTreeNode
    {
        std::vector<char> Keys;
        std::vector<BTreeNode*> Children{};
        bool IsLeaf{};

        [[nodiscard]] int GetKeyCount() const
        {
            return static_cast<int>(Keys.size());
        }

        explicit BTreeNode() = default;
    };

    class BTree
    {
    public:
        [[nodiscard]] BTreeNode*
        GetRoot() const
        {
            return Root;
        }

        void SetRoot(BTreeNode* const root)
        {
            Root = root;
        }

        [[nodiscard]] std::vector<BTreeNode*> GetNodes() const
        {
            return Nodes;
        }

        [[nodiscard]] int GetDegree() const
        {
            return Degree;
        }

        void SetDegree(const int degree)
        {
            Degree = degree;
        }

        /// <summary>
        /// Split a node
        /// </summary>
        /// <param name="node">internal node</param>
        /// <param name="index">index</param>
        /// <returns>void</returns>
        void SplitChild(BTreeNode* node, const int index);

        /// <summary>
        /// Insert key
        /// </summary>
        /// <param name="node">internal node</param>
        /// <param name="key">key</param>
        /// <returns>void</returns>
        void InsertNonFull(BTreeNode* node, const char key);

        /// <summary>
        /// Insert key to the tree
        /// </summary>
        /// <param name="key">key to insert</param>
        /// <returns>void</returns>
        void Insert(const char key);

        /// <summary>
        /// Search the key
        /// </summary>
        /// <param name="key">key to search for</param>
        /// <returns>node and key index pair</returns>
        std::pair<BTreeNode*, const int> Search(const char key);

    protected:
        BTreeNode* Root{};
        std::vector<BTreeNode*> Nodes{};
        int Degree{};

        /// <summary>
        /// Insert key to the tree
        /// </summary>
        /// <param name="ref">reference node for insert</param>
        /// <param name="key">key to insert</param>
        /// <returns>void</returns>
        void Insert(BTreeNode* ref, const char key);

        /// <summary>
        /// Search the key
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>node and key index pair</returns>
        std::pair<BTreeNode*, const int> Search(BTreeNode* ref, const char key);
    };
}

#endif
