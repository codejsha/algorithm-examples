#include "reverse_list.h"

#include <gtest/gtest.h>

GTEST_TEST(ReverseList, ReverseSubList)
{
    const auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node5});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, node2});

    const auto expected = std::vector<int>{11, 3, 5, 7, 2};
    auto result = ReverseList::ReverseSubList(node1, 2, 4);
    for (const auto& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}
