#include "print_stack.h"

#include <iostream>
#include <stack>

void PrintStack::PrintLinkedListInReverseOrder(const std::shared_ptr<LinkedList::Node<int>>& head)
{
    std::stack<std::shared_ptr<LinkedList::Node<int>>> nodes;
    auto node = head;
    while (node != nullptr)
    {
        nodes.push(node);
        node = node->next;
    }

    while (!nodes.empty())
    {
        std::cout << nodes.top()->data << " ";
        nodes.pop();
    }
}
