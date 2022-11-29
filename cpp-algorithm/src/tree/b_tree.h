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

        [[nodiscard]] auto GetKeyCount() const -> int
        {
            return static_cast<int>(Keys.size());
        }

        explicit BTreeNode() = default;
    };

    class BTree
    {
    public:
        [[nodiscard]] auto
        GetRoot() const -> BTreeNode*
        {
            return Root;
        }

        void SetRoot(BTreeNode* const root)
        {
            Root = root;
        }

        [[nodiscard]] auto GetNodes() const -> std::vector<BTreeNode*>
        {
            return Nodes;
        }

        [[nodiscard]] auto GetDegree() const -> int
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
        void SplitChild(BTreeNode* node, int index);

        /// <summary>
        /// Insert key
        /// </summary>
        /// <param name="node">internal node</param>
        /// <param name="key">key</param>
        /// <returns>void</returns>
        void InsertNonFull(BTreeNode* node, char key);

        /// <summary>
        /// Insert key to the tree
        /// </summary>
        /// <param name="key">key to insert</param>
        /// <returns>void</returns>
        void Insert(char key);

        /// <summary>
        /// Search the key
        /// </summary>
        /// <param name="key">key to search for</param>
        /// <returns>node and key index pair</returns>
        auto Search(char key) -> std::pair<BTreeNode*, const int>;

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
        void Insert(BTreeNode* ref, char key);

        /// <summary>
        /// Search the key
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>node and key index pair</returns>
        auto Search(BTreeNode* ref, char key) -> std::pair<BTreeNode*, const int>;
    };
}

#endif
