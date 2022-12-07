#ifndef CPP_ALGORITHM_LIST_PALINDROME_H
#define CPP_ALGORITHM_LIST_PALINDROME_H

#include "linked_list.h"

namespace ListPalindrome
{
    /// @brief Check if a singly linked list is a palindrome.
    /// @param list the head of the list
    /// @return whether the list is a palindrome
    auto IsListPalindrome(const std::shared_ptr<LinkedList::Node<int>>& list) -> bool;
}

#endif
