#include "list_cycle.h"

#include <gtest/gtest.h>

GTEST_TEST(ListCycleTest, HasCycle1_1)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    const auto result = ListCycle::HasCycle1(node1);
    EXPECT_EQ(2, result->data);
}

GTEST_TEST(ListCycleTest, HasCycle1_2)
{
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});
    node2->next = node1;

    const auto result = ListCycle::HasCycle1(node1);
    EXPECT_EQ(1, result->data);
}

GTEST_TEST(ListCycleTest, HasCycle1_3)
{
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});

    const auto result = ListCycle::HasCycle1(node1);
    EXPECT_EQ(nullptr, result);
    EXPECT_NE(node1, result);
}

GTEST_TEST(ListCycleTest, HasCycle2_1)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    const auto result = ListCycle::HasCycle2(node1);
    EXPECT_EQ(2, result->data);
}

GTEST_TEST(ListCycleTest, HasCycle2_2)
{
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});
    node2->next = node1;

    const auto result = ListCycle::HasCycle2(node1);
    EXPECT_EQ(1, result->data);
}

GTEST_TEST(ListCycleTest, HasCycle2_3)
{
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});

    const auto result = ListCycle::HasCycle2(node1);
    EXPECT_EQ(nullptr, result);
    EXPECT_NE(node1, result);
}

GTEST_TEST(ListCycleTest, HasCycle3_1)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    const auto result = ListCycle::HasCycle3(node1);
    EXPECT_EQ(1, result);
}

GTEST_TEST(ListCycleTest, HasCycle3_2)
{
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});
    node2->next = node1;

    const auto result = ListCycle::HasCycle3(node1);
    EXPECT_EQ(0, result);
}

GTEST_TEST(ListCycleTest, HasCycle3_3)
{
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});

    const auto result = ListCycle::HasCycle3(node1);
    EXPECT_EQ(-1, result);
}
