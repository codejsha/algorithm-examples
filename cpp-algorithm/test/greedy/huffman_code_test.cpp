#include "huffman_code.h"

#include <gtest/gtest.h>
#include <ranges>

GTEST_TEST(HuffmanCode, HuffmanCode)
{
    const auto freq_map = std::map<int, char>{
        {5, 'f'}, {9, 'e'}, {12, 'c'}, {13, 'b'}, {16, 'd'}, {45, 'a'}};
    const auto expected = std::map<char, std::string>{
        {'a', "0"}, {'b', "101"}, {'c', "100"}, {'d', "111"}, {'e', "1101"}, {'f', "1100"}};

    const auto root_node = Huffman::HuffmanCode(freq_map);
    const auto result = new std::map<char, std::string>{};
    Huffman::TraversalHuffmanCode(root_node, "", *result);

    for (const auto& [key, value] : expected)
    {
        ASSERT_EQ(value, result->at(key));
    }
}
