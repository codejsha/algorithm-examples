#ifndef CPP_ALGORITHM_REVERSE_LIST_H
#define CPP_ALGORITHM_REVERSE_LIST_H

#include "linked_list.h"

#include <utility>

namespace ReverseList
{
    /**
     * \brief Rearranges the sublist of the list in reverse order.
     * \details The sublist is defined by the start and finish indices.
     * This task has O(f) time complexity, f is the index of the finish node.
     * \param list the head of the list
     * \param start start index of the sublist
     * \param finish end index of the sublist
     * \return the head of the list
     */
    std::shared_ptr<LinkedList::Node<int>> ReverseSubList(
        std::shared_ptr<LinkedList::Node<int>> list,
        int start,
        int finish);
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> ReverseList::ReverseSubList(
    std::shared_ptr<LinkedList::Node<int>> list,
    int start,
    const int finish)
{
    const auto dummy_head = std::make_shared<LinkedList::Node<int>>(LinkedList::Node<int>{0, std::move(list)});
    auto sublist_head = dummy_head;

    int k = 1;
    while (k++ < start)
    {
        sublist_head = sublist_head->next;
    }

    const auto sublist_iter = sublist_head->next;
    while (start++ < finish)
    {
        auto temp = sublist_iter->next;
        sublist_iter->next = temp->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
    }

    return dummy_head->next;
}

#endif
