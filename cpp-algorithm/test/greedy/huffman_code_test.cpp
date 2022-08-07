#include "tree.h"
#include "huffman_code.h"
#include <gtest/gtest.h>
#include <ranges>

TEST(HuffmanCodeTest, Simple)
{
    const auto freqMap = std::map<int, char>{
        {5, 'f'}, {9, 'e'}, {12, 'c'}, {13, 'b'}, {16, 'd'}, {45, 'a'}};
    const auto expecteMap = std::map<char, std::string>{
        {'a', "0"}, {'b', "101"}, {'c', "100"}, {'d', "111"}, {'e', "1101"}, {'f', "1100"}};

    const auto rootNode = Huffman::HuffmanCode(freqMap);
    const auto result = new std::map<char, std::string>{};
    Huffman::TraversalHuffmanCode(rootNode, "", *result);

    for (const auto& [key, value] : expecteMap)
    {
        ASSERT_EQ(value, result->at(key));
    }
}
