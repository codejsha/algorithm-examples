#include "list_cycle.h"

/// @brief Advance the node index by the difference of the length of two lists.
/// @param difference difference of the length of two lists
/// @param list list longer than the other list
void AdvanceListByDifference(int difference, std::shared_ptr<LinkedList::Node<int>>& list)
{
    while (difference--)
    {
        list = list->next;
    }
}

std::shared_ptr<LinkedList::Node<int>> ListCycle::HasCycle1(const std::shared_ptr<LinkedList::Node<int>>& list)
{
    auto fast = list;
    auto slow = list;

    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            fast = list;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }

            return fast;
        }
    }

    return nullptr;
}

std::shared_ptr<LinkedList::Node<int>> ListCycle::HasCycle2(const std::shared_ptr<LinkedList::Node<int>>& list)
{
    auto fast = list;
    auto slow = list;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            // There is a cycle, so now let's calculate the cycle length
            int cycle_length = 0;
            do
            {
                ++cycle_length;
                fast = fast->next;
            } while (slow != fast);

            // Find the start of the cycle
            auto cycle_start = list;
            while (cycle_length--)
            {
                cycle_start = cycle_start->next;
            }

            auto iter = list;
            while (iter != cycle_start)
            {
                iter = iter->next;
                cycle_start = cycle_start->next;
            }

            return iter;
        }
    }

    return nullptr;
}

int ListCycle::HasCycle3(const std::shared_ptr<LinkedList::Node<int>>& list)
{
    auto fast = list;
    auto slow = list;

    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            fast = list;
            auto index = 0;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
                ++index;
            }
            return index;
        }
    }

    return -1;
}

std::shared_ptr<LinkedList::Node<int>> ListCycle::OverlappingNoCycleList(
    std::shared_ptr<LinkedList::Node<int>>& list1,
    std::shared_ptr<LinkedList::Node<int>>& list2)
{
    const auto list1_length = LinkedList::Length(list1);
    const auto list2_length = LinkedList::Length(list2);

    AdvanceListByDifference(list1_length - list2_length, list1_length > list2_length ? list1 : list2);

    while (list1 && list2 && list1 != list2)
    {
        list1 = list1->next;
        list2 = list2->next;
    }

    return list1;
}
