#ifndef CPP_ALGORITHM_MAX_STACK_ELEMENT_H
#define CPP_ALGORITHM_MAX_STACK_ELEMENT_H

#include <stack>
#include <stdexcept>

namespace MaxStackElement
{
    /// @brief Custom stack that stores the maximum element.
    class Stack
    {
    public:
        bool Empty() const
        {
            return std::empty(element_with_cached_max_);
        }

        int Max() const
        {
            if (Empty())
            {
                throw std::length_error("Empty stack!");
            }
            return element_with_cached_max_.top().max;
        }

        int Pop()
        {
            if (Empty())
            {
                throw std::length_error("Empty stack!");
            }
            const auto pop_element = element_with_cached_max_.top().element;
            element_with_cached_max_.pop();
            return pop_element;
        }

        void Push(const int x)
        {
            element_with_cached_max_.emplace(
                ElementWithCachedMax{x, std::max(x, Empty() ? x : Max())});
        }

    private:
        struct ElementWithCachedMax
        {
            int element;
            int max;
        };

        /// @brief Caches the maximum element in the stack.
        /// @details Caches the maximum among the elements below the current element.
        std::stack<ElementWithCachedMax> element_with_cached_max_;
    };
}

#endif
