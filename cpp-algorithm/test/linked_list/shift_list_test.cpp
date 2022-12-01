#include "shift_list.h"

#include <gtest/gtest.h>

GTEST_TEST(ShiftListTest, CyclicallyRightShiftList)
{
    auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    auto expected = std::vector<int>{0, -4, 3, 2};
    auto result = ShiftList::CyclicallyRightShiftList(node1, 2);
    for (const auto& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}