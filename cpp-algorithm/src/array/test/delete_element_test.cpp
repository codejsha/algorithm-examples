#include "delete_element.h"

#include <gtest/gtest.h>

GTEST_TEST(DeleteElement, DeleteDuplicate_ConsecutiveElements)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    const auto expected = std::vector<int>{2, 3, 5, 7, 11, 13};
    const auto result = DeleteElement::DeleteDuplicates(numbers);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(DeleteElement, DeleteDuplicateElements_UnorderedElements)
{
    auto numbers = std::vector<int>{2, 11, 5, 11, 7, 11, 5, 3, 13};
    const auto expected = std::vector<int>{2, 3, 5, 7, 11, 13};
    const auto result = DeleteElement::DeleteDuplicateElements(numbers);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(DeleteElement, DeleteSpecificElements_RemoveElement)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    constexpr int element = 11;
    const auto expected = std::vector<int>{2, 3, 5, 5, 7, 13};
    const auto result = DeleteElement::DeleteSpecificElements(numbers, element);
    EXPECT_EQ(expected, result);
}
