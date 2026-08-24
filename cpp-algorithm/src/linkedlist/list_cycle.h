#ifndef CPP_ALGORITHM_LIST_CYCLE_H
#define CPP_ALGORITHM_LIST_CYCLE_H

#include "linked_list.h"

namespace ListCycle
{
    /**
     * \brief Determine if a linked list has a cycle.
     * \details Given a linked list, determine if it has a cycle in it.
     * \param list the head of the linked list
     * \return if the linked list has a cycle, return start node of the cycle, otherwise return nullptr
     */
    std::shared_ptr<LinkedList::Node<int>> HasCycle1(
        const std::shared_ptr<LinkedList::Node<int>>& list);

    /**
     * \brief Determine if a linked list has a cycle.
     * \details Given a linked list, determine if it has a cycle in it.
     * This task has O(f) + O(c) = O(n) time complexity(f is count of nodes before cycle,
     * c is length of nodes in cycle, n is total nodes in list).
     * \param list the head of the linked list
     * \return if the linked list has a cycle, return start node of the cycle, otherwise return nullptr
     */
    std::shared_ptr<LinkedList::Node<int>> HasCycle2(
        const std::shared_ptr<LinkedList::Node<int>>& list);

    /**
     * \brief Determine if a linked list has a cycle.
     * \details Given a linked list, determine if it has a cycle in it.
     * \param list the head of the linked list
     * \return if the linked list has a cycle, return start index of the cycle, otherwise return -1
     */
    int HasCycle3(
        const std::shared_ptr<LinkedList::Node<int>>& list);

    /**
     * \brief Given two lists, determine if they overlap.
     * \param list1 the head of the first list
     * \param list2 the head of the second list
     * \return if the two lists overlap, return the first overlapping node, otherwise return nullptr
     */
    std::shared_ptr<LinkedList::Node<int>> OverlappingNoCycleList(
        std::shared_ptr<LinkedList::Node<int>>& list1,
        std::shared_ptr<LinkedList::Node<int>>& list2);

    /**
     * \brief Given two lists with cycles, determine if they overlap.
     * \param list1 the head of the first list
     * \param list2 the head of the second list
     * \return if the two lists overlap, return the first overlapping node, otherwise return nullptr
     */
    std::shared_ptr<LinkedList::Node<int>> OverlappingCycleList(
        std::shared_ptr<LinkedList::Node<int>>& list1,
        std::shared_ptr<LinkedList::Node<int>>& list2);
}

// ----------------------------------------------------------------------------
/**
 * \brief Advance the node index by the difference of the length of two lists.
 * \param difference difference of the length of two lists
 * \param list list longer than the other list
 */
inline void AdvanceListByDifference(
    int difference,
    std::shared_ptr<LinkedList::Node<int>>& list)
{
    while (difference--)
    {
        list = list->next;
    }
}

// ----------------------------------------------------------------------------
/**
 * \brief The distance between list1 and list2.
 * \param list1 the head of the first list
 * \param list2 the head of the second list
 * \return overlapping distance between list1 and list2
 */
inline int OverlappingDistance(
    std::shared_ptr<LinkedList::Node<int>>& list1,
    std::shared_ptr<LinkedList::Node<int>>& list2)
{
    int distance = 0;
    while (list1 != list2)
    {
        list1 = list1->next;
        ++distance;
    }
    return distance;
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> ListCycle::HasCycle1(
    const std::shared_ptr<LinkedList::Node<int>>& list)
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

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> ListCycle::HasCycle2(
    const std::shared_ptr<LinkedList::Node<int>>& list)
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

// ----------------------------------------------------------------------------
inline int ListCycle::HasCycle3(
    const std::shared_ptr<LinkedList::Node<int>>& list)
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
            int index = 0;
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

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> ListCycle::OverlappingNoCycleList(
    std::shared_ptr<LinkedList::Node<int>>& list1,
    std::shared_ptr<LinkedList::Node<int>>& list2)
{
    const int list1_length = LinkedList::Length(list1);
    const int list2_length = LinkedList::Length(list2);

    AdvanceListByDifference(list1_length - list2_length, list1_length > list2_length ? list1 : list2);

    while (list1 && list2 && list1 != list2)
    {
        list1 = list1->next;
        list2 = list2->next;
    }

    return list1;
}

// ----------------------------------------------------------------------------
inline std::shared_ptr<LinkedList::Node<int>> ListCycle::OverlappingCycleList(
    std::shared_ptr<LinkedList::Node<int>>& list1,
    std::shared_ptr<LinkedList::Node<int>>& list2)
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

#endif
