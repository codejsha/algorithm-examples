#ifndef CPP_ALGORITHM_HUFFMAN_CODE_H
#define CPP_ALGORITHM_HUFFMAN_CODE_H

#include <map>
#include <queue>
#include <string>

namespace Huffman
{
    /**
     * \brief Node in full binary tree for Huffman code.
     */
    struct HuffmanNode
    {
        HuffmanNode* left;
        HuffmanNode* right;
        int key;
        char ch;
        int freq;

        HuffmanNode(const int key, const char ch, const int freq)
            : left(nullptr), right(nullptr), key(key), ch(ch), freq(freq)
        {
        }
    };

    /**
     * \brief Comparator for minimal heap builds
     */
    class MinComparator
    {
    public:
        bool operator()(const HuffmanNode* l, const HuffmanNode* r) const { return (l->freq > r->freq); }
    };

    /**
     * \brief Huffman code algorithm.
     * \param freq_map a map of char and frequency pairs
     * \return root node
     */
    HuffmanNode* HuffmanCode(const std::map<int, char>& freq_map);

    /**
     * \brief Tree traversal to get the Huffman code
     * \param root root node that starts the tree traversal
     * \param code prefix code
     * \param result result of tree traversal
     */
    void TraversalHuffmanCode(
        const HuffmanNode* root,
        const std::string& code,
        std::map<char, std::string>& result);
}

// ----------------------------------------------------------------------------
inline Huffman::HuffmanNode* Huffman::HuffmanCode(const std::map<int, char>& freq_map)
{
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, MinComparator> min_queue;
    for (auto [freq, ch] : freq_map)
    {
        min_queue.push(new HuffmanNode{freq, ch, freq});
    }

    while (static_cast<int>(min_queue.size()) != 1)
    {
        const auto left = min_queue.top();
        min_queue.pop();
        const auto right = min_queue.top();
        min_queue.pop();

        const int key = left->key + right->key;
        auto node = new HuffmanNode{key, '-', left->freq + right->freq};
        node->left = left;
        node->right = right;

        min_queue.push(node);
    }

    return min_queue.top();
}

// ----------------------------------------------------------------------------
inline void Huffman::TraversalHuffmanCode(
    const HuffmanNode* root,
    const std::string& code,
    std::map<char, std::string>& result)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->ch != '-')
    {
        result.insert(std::pair(root->ch, code));
    }

    TraversalHuffmanCode(root->left, code + "0", result);
    TraversalHuffmanCode(root->right, code + "1", result);
}

#endif
