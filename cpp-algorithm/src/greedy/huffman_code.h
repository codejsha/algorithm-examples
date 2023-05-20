#ifndef CPP_ALGORITHM_HUFFMAN_CODE_H
#define CPP_ALGORITHM_HUFFMAN_CODE_H

#include <map>
#include <string>

namespace Huffman
{
    /// @brief Node in full binary tree for Huffman code.
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

    /// @brief Comparator for minimal heap builds
    class MinComparator
    {
    public:
        auto operator()(const HuffmanNode* l, const HuffmanNode* r) const -> bool { return (l->freq > r->freq); }
    };

    /// @brief Huffman code algorithm.
    /// @param freq_map a map of char and frequency pairs
    /// @return root node
    auto HuffmanCode(const std::map<int, char>& freq_map) -> HuffmanNode*;

    /// @brief Tree traversal to get the Huffman code
    /// @param root root node that starts the tree traversal
    /// @param code prefix code
    /// @param result result of tree traversal
    void TraversalHuffmanCode(const HuffmanNode* root, std::string code, std::map<char, std::string>& result);
}

#endif
