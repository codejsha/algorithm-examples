#ifndef CPP_ALGORITHM_HUFFMAN_CODE_H
#define CPP_ALGORITHM_HUFFMAN_CODE_H

#include "tree.h"

#include <map>
#include <string>

namespace Huffman
{
    /// <summary>
    /// Node in full binary tree for Huffman code
    /// </summary>
    struct HuffmanNode : Tree::BinaryNode<HuffmanNode>
    {
        char Ch;
        int Freq;

        explicit HuffmanNode(const int key, const char ch, const int freq)
            : BinaryNode<HuffmanNode>(key), Ch(ch), Freq(freq)
        {
        }
    };

    /// <summary>
    /// Comparator for minimal heap builds
    /// </summary>
    class MinComparator
    {
    public:
        bool operator()(const HuffmanNode* l, const HuffmanNode* r) const
        {
            return (l->Freq > r->Freq);
        }
    };

    /// <summary>
    /// Huffman code algorithm
    /// </summary>
    /// <param name="freqMap">a map of char and frequency pairs</param>
    /// <returns>root node</returns>
    HuffmanNode* HuffmanCode(const std::map<int, char>& freqMap);

    /// <summary>
    /// Tree traversal to get the Huffman code
    /// </summary>
    /// <param name="root">root node that starts the tree traversal</param>
    /// <param name="code">prefix code</param>
    /// <param name="result">result of tree traversal</param>
    /// <returns>void</returns>
    void TraversalHuffmanCode(const HuffmanNode* root, std::string code, std::map<char, std::string>& result);
}

#endif
