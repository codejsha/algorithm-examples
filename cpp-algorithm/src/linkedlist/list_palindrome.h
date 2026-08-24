#ifndef CPP_ALGORITHM_LIST_PALINDROME_H
#define CPP_ALGORITHM_LIST_PALINDROME_H

#include "linked_list.h"

namespace ListPalindrome
{
    /**
     * \brief Check if a singly linked list is a palindrome.
     * \param list the head of the list
     * \return whether the list is a palindrome
     */
    bool IsListPalindrome(
        const std::shared_ptr<LinkedList::Node<int>>& list);
}

// ----------------------------------------------------------------------------
inline bool ListPalindrome::IsListPalindrome(
    const std::shared_ptr<LinkedList::Node<int>>& list)
{
    // Find the middle of the list
    auto slow = list;
    auto fast = list;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    std::shared_ptr<LinkedList::Node<int>> later = nullptr;
    while (slow)
    {
        const auto temp = slow->next;
        slow->next = later;
        later = slow;
        slow = temp;
    }

    // Compare the first and second halves of the list
    auto first_half = list;
    auto second_half = later;
    while (second_half)
    {
        if (first_half->data != second_half->data)
        {
            return false;
        }

        first_half = first_half->next;
        second_half = second_half->next;
    }

    return true;
}

#endif
