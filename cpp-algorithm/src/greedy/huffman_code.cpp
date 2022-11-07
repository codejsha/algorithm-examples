#include "huffman_code.h"

#include <queue>

Huffman::HuffmanNode* Huffman::HuffmanCode(const std::map<int, char>& freqMap)
{
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, MinComparator> minQueue;
    for (auto [freq, ch] : freqMap)
    {
        minQueue.push(new HuffmanNode{freq, ch, freq});
    }

    while (static_cast<int>(minQueue.size()) != 1)
    {
        const auto left = minQueue.top();
        minQueue.pop();
        const auto right = minQueue.top();
        minQueue.pop();

        const auto key = left->Key + right->Key;
        auto node = new HuffmanNode{key, '-', left->Freq + right->Freq};
        node->Left = left;
        node->Right = right;

        minQueue.push(node);
    }

    return minQueue.top();
}

void Huffman::TraversalHuffmanCode(const HuffmanNode* root, std::string code, std::map<char, std::string>& result)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->Ch != '-')
    {
        result.insert(std::pair(root->Ch, code));
    }

    TraversalHuffmanCode(root->Left, code + "0", result);
    TraversalHuffmanCode(root->Right, code + "1", result);
}
