#include "list_palindrome.h"

auto ListPalindrome::IsListPalindrome(const std::shared_ptr<LinkedList::Node<int>>& list) -> bool
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
