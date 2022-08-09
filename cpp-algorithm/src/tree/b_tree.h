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
        [[nodiscard]] auto GetRoot() const -> BTreeNode*
        {
            return Root;
        }

        auto SetRoot(BTreeNode* const root) -> void
        {
            Root = root;
        }

        [[nodiscard]] auto GetNodes() const -> std::vector<BTreeNode*>
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
        auto SplitChild(BTreeNode* node, const int index) -> void;

        /// <summary>
        /// Insert key if node is full
        /// </summary>
        /// <param name="node">internal node</param>
        /// <param name="key">key</param>
        /// <returns>void</returns>
        auto InsertNonFull(BTreeNode* node, const char key) -> void;

        /// <summary>
        /// Insert key to the tree
        /// </summary>
        /// <param name="key">key to insert</param>
        /// <returns>void</returns>
        auto Insert(const char key) -> void;

        /// <summary>
        /// Search the key
        /// </summary>
        /// <param name="key">key to search for</param>
        /// <returns>node and key index pair</returns>
        auto Search(const char key) -> std::pair<BTreeNode*, const int>;

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
        auto Insert(BTreeNode* ref, const char key) -> void;

        /// <summary>
        /// Search the key
        /// </summary>
        /// <param name="ref">reference node for tree search</param>
        /// <param name="key">key to search for</param>
        /// <returns>node and key index pair</returns>
        auto Search(BTreeNode* ref, const char key) -> std::pair<BTreeNode*, const int>;
    };
} // namespace Tree

#endif
