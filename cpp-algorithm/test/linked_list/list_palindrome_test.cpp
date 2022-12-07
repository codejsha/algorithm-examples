#include "list_palindrome.h"

#include <gtest/gtest.h>

GTEST_TEST(ListPalindromeTest, IsListPalindrome_1)
{
    const auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node5});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});

    const auto result = ListPalindrome::IsListPalindrome(node1);
    EXPECT_TRUE(result);
}
