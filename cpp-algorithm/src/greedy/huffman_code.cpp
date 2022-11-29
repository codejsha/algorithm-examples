#include "huffman_code.h"

#include <queue>

auto Huffman::HuffmanCode(const std::map<int, char>& freq_map) -> HuffmanNode*
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

        const auto key = left->Key + right->Key;
        auto node = new HuffmanNode{key, '-', left->Freq + right->Freq};
        node->Left = left;
        node->Right = right;

        min_queue.push(node);
    }

    return min_queue.top();
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
