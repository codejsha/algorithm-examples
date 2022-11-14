#ifndef CPP_ALGORITHM_HUFFMAN_CODE_H
#define CPP_ALGORITHM_HUFFMAN_CODE_H

#include "tree.h"

#include <map>
#include <string>

namespace Huffman
{
    /// @brief Node in full binary tree for Huffman code.
    struct HuffmanNode : Tree::BinaryNode<HuffmanNode>
    {
        char Ch;
        int Freq;

        explicit HuffmanNode(const int key, const char ch, const int freq)
            : BinaryNode<HuffmanNode>(key), Ch(ch), Freq(freq)
        {
        }
    };

    /// @brief Comparator for minimal heap builds
    class MinComparator
    {
    public:
        bool operator()(const HuffmanNode* l, const HuffmanNode* r) const
        {
            return (l->Freq > r->Freq);
        }
    };

    /// @brief Huffman code algorithm.
    /// @param freq_map a map of char and frequency pairs
    /// @return root node
    HuffmanNode* HuffmanCode(const std::map<int, char>& freq_map);

    /// @brief Tree traversal to get the Huffman code
    /// @param root root node that starts the tree traversal
    /// @param code prefix code
    /// @param result result of tree traversal
    void TraversalHuffmanCode(const HuffmanNode* root, std::string code, std::map<char, std::string>& result);
}

#endif
