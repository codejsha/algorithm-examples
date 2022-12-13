#include "order_list_node.h"

#include <gtest/gtest.h>

GTEST_TEST(OrderListNode, ListPivoting)
{
    auto node7 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, nullptr});
    auto node6 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node7});
    auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node6});
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, node5});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    auto expected = std::vector<int>{3, 2, 2, 5, 7, 11, 11};
    auto result = OrderListNode::ListPivoting(node1, 7);
    EXPECT_EQ(expected.size(), LinkedList::Length(result));
    for (const auto& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}
