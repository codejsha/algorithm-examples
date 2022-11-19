#include "list_cycle.h"

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
