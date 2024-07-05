#include "merge_list.h"

#include <gtest/gtest.h>

GTEST_TEST(MergeList, MergeTwoSortedLinkedList1)
{
    const auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    const auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_a3});
    const auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_a2});

    const auto node_b3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    const auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_b3});
    const auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_b2});

    auto result = MergeList::MergeTwoSortedLinkedList(node_a1, node_b1);
    const auto expected = std::vector<int>{1, 1, 2, 3, 4, 4};
    for (const int& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}

GTEST_TEST(MergeList, MergeTwoSortedLinkedList2)
{
    const auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{7, nullptr});
    const auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{5, node_a3});
    const auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_a2});

    const auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{11, nullptr});
    const auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_b2});

    auto result = MergeList::MergeTwoSortedLinkedList(node_a1, node_b1);
    const auto expected = std::vector<int>{2, 3, 5, 7, 11};
    for (const int& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}

GTEST_TEST(MergeList, MergeEvenOddLinkedList)
{
    const auto node4 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{-4, nullptr});
    const auto node3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, node4});
    const auto node2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node3});
    const auto node1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node2});

    auto result = MergeList::MergeEvenOddLinkedList(node1);
    const auto expected = std::vector<int>{3, 0, 2, -4};
    for (const int& i : expected)
    {
        ASSERT_EQ(i, result->data);
        result = result->next;
    }
}
