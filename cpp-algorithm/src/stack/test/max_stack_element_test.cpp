#include "max_stack_element.h"

#include <gtest/gtest.h>

GTEST_TEST(MaxStackElement, EmptyStack)
{
    auto stack = MaxStackElement::Stack{};
    ASSERT_TRUE(stack.Empty());
    ASSERT_THROW(stack.Max(), std::length_error);
    ASSERT_THROW(stack.Pop(), std::length_error);
}

GTEST_TEST(MaxStackElement, PushAndPop)
{
    auto stack = MaxStackElement::Stack{};
    stack.Push(1);
    ASSERT_FALSE(stack.Empty());
    ASSERT_EQ(1, stack.Max());
    ASSERT_EQ(1, stack.Pop());
    ASSERT_TRUE(stack.Empty());
    ASSERT_THROW(stack.Max(), std::length_error);
    ASSERT_THROW(stack.Pop(), std::length_error);
}

GTEST_TEST(MaxStackElement, Max)
{
    auto stack = MaxStackElement::Stack{};
    stack.Push(3);
    stack.Push(2);
    stack.Push(4);
    stack.Push(1);
    stack.Push(5);
    ASSERT_FALSE(stack.Empty());
    ASSERT_EQ(5, stack.Max());
    ASSERT_EQ(5, stack.Pop());
    ASSERT_EQ(4, stack.Max());
}
