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

/// @brief The distance between list1 and list2.
/// @param list1 the head of the first list
/// @param list2 the head of the second list
/// @return overlapping distance between list1 and list2
auto OverlappingDistance(std::shared_ptr<LinkedList::Node<int>>& list1, std::shared_ptr<LinkedList::Node<int>>& list2)
    -> int
{
    auto distance = 0;
    while (list1 != list2)
    {
        list1 = list1->next;
        ++distance;
    }
    return distance;
}

auto ListCycle::HasCycle1(const std::shared_ptr<LinkedList::Node<int>>& list) -> std::shared_ptr<LinkedList::Node<int>>
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

auto ListCycle::HasCycle2(const std::shared_ptr<LinkedList::Node<int>>& list) -> std::shared_ptr<LinkedList::Node<int>>
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
            auto cycle_length = 0;
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

auto ListCycle::HasCycle3(const std::shared_ptr<LinkedList::Node<int>>& list) -> int
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

auto ListCycle::OverlappingNoCycleList(std::shared_ptr<LinkedList::Node<int>>& list1,
                                       std::shared_ptr<LinkedList::Node<int>>& list2)
    -> std::shared_ptr<LinkedList::Node<int>>
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

auto ListCycle::OverlappingCycleList(std::shared_ptr<LinkedList::Node<int>>& list1,
                                     std::shared_ptr<LinkedList::Node<int>>& list2)
    -> std::shared_ptr<LinkedList::Node<int>>
{
    auto root1 = HasCycle1(list1);
    auto root2 = HasCycle1(list2);

    // both lists do not have cycles
    if (!root1 && !root2)
    {
        return OverlappingNoCycleList(list1, list2);
    }

    // one list has cycle and the other does not
    if ((root1 && !root2) || (!root1 && root2))
    {
        return nullptr;
    }

    // both lists have cycles
    auto temp = root2;
    do
    {
        temp = temp->next;
    } while (temp != root1 && temp != root2);

    return temp == root1 ? root2 : nullptr;
}
