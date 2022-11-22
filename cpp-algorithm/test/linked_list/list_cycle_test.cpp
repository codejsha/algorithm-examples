#include "list_cycle.h"

#include <gtest/gtest.h>

GTEST_TEST(ListHasCycleTest, HasCycle1_1)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    const auto result = ListCycle::HasCycle1(node1);
    EXPECT_EQ(2, result->data);
}

GTEST_TEST(ListHasCycleTest, HasCycle1_2)
{
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});
    node2->next = node1;

    const auto result = ListCycle::HasCycle1(node1);
    EXPECT_EQ(1, result->data);
}

GTEST_TEST(ListHasCycleTest, HasCycle1_3)
{
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});

    const auto result = ListCycle::HasCycle1(node1);
    EXPECT_EQ(nullptr, result);
    EXPECT_NE(node1, result);
}

GTEST_TEST(ListHasCycleTest, HasCycle2_1)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    const auto result = ListCycle::HasCycle2(node1);
    EXPECT_EQ(2, result->data);
}

GTEST_TEST(ListHasCycleTest, HasCycle2_2)
{
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});
    node2->next = node1;

    const auto result = ListCycle::HasCycle2(node1);
    EXPECT_EQ(1, result->data);
}

GTEST_TEST(ListHasCycleTest, HasCycle2_3)
{
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});

    const auto result = ListCycle::HasCycle2(node1);
    EXPECT_EQ(nullptr, result);
    EXPECT_NE(node1, result);
}

GTEST_TEST(ListHasCycleTest, HasCycle3_1)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});
    node4->next = node2;

    const auto result = ListCycle::HasCycle3(node1);
    EXPECT_EQ(1, result);
}

GTEST_TEST(ListHasCycleTest, HasCycle3_2)
{
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, nullptr});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node2});
    node2->next = node1;

    const auto result = ListCycle::HasCycle3(node1);
    EXPECT_EQ(0, result);
}

GTEST_TEST(ListHasCycleTest, HasCycle3_3)
{
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, nullptr});

    const auto result = ListCycle::HasCycle3(node1);
    EXPECT_EQ(-1, result);
}

GTEST_TEST(OverlappingCycleListTest, OverlappingNoCycleLists_1)
{
    auto node_3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_3});
    auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_a2});

    auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_3});
    auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_b2});

    auto result = ListCycle::OverlappingNoCycleList(node_a1, node_b1);
    EXPECT_EQ(4, result->data);
}

GTEST_TEST(OverlappingCycleListTest, OverlappingNoCycleLists_2)
{
    auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, nullptr});
    auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node_a3});
    auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_a2});

    auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, nullptr});
    auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_b2});

    auto result = ListCycle::OverlappingNoCycleList(node_a1, node_b1);
    EXPECT_EQ(nullptr, result);
}
