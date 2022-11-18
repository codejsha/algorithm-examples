#include "merge_linked_list.h"

#include <gtest/gtest.h>

GTEST_TEST(MergeLinkedListTest, MergeTwoSortedLinkedList)
{
    const auto node_a3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    const auto node_a2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{2, node_a3});
    const auto node_a1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_a2});

    const auto node_b3 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{4, nullptr});
    const auto node_b2 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{3, node_b3});
    const auto node_b1 = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{1, node_b2});

    auto result = MergeLinkedList::MergeTwoSortedLinkedList(node_a1, node_b1);
    const auto expected = std::vector<int>{1, 1, 2, 3, 4, 4};
    for (const auto& i : expected)
    {
        EXPECT_EQ(i, result->data);
        result = result->next;
    }
}
