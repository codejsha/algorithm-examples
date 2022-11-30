#include "delete_list_node.h"

#include <gtest/gtest.h>

GTEST_TEST(DeleteListNodeTest, DeleteNodeFromList)
{
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    DeleteListNode::DeleteNodeFromList(node3);
    const auto length = LinkedList::Length(node1);
    EXPECT_EQ(3, length);
}

GTEST_TEST(DeleteListNodeTest, DeleteNodeKthLast)
{
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    auto result = DeleteListNode::DeleteNodeKthLast(node1, 2);
    const auto length = LinkedList::Length(result);
    EXPECT_EQ(3, length);

    const auto expected = std::vector<int>{3, 2, -4};
    for (const auto& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}

GTEST_TEST(DeleteListNodeTest, DeleteDuplicateNode)
{
    auto node7 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, nullptr});
    auto node6 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, node7});
    auto node5 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node6});
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node5});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node2});

    auto result = DeleteListNode::DeleteDuplicateNode(node1);
    const auto length = LinkedList::Length(result);
    EXPECT_EQ(5, length);

    const auto expected = std::vector<int>{2, 3, 5, 7, 11};
    for (const auto& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}
