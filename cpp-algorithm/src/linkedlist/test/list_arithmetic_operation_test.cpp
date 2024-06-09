#include "list_arithmetic_operation.h"

#include <gtest/gtest.h>

GTEST_TEST(ListArithmetic, AddTwoNumbers)
{
    auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_a3});
    auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_a2});

    auto node_b3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{9, nullptr});
    auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node_b3});
    auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, node_b2});

    auto expected = std::vector<int>{0, 2, 3, 1};
    auto result = ListArithmetic::AddTwoNumbers(node_a1, node_b1);
    for (const auto& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}
