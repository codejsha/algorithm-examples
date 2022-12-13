#include "delete_element.h"

#include <gtest/gtest.h>

GTEST_TEST(DeleteElement, DeleteDuplicate)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    const auto expected = std::vector<int>{2, 3, 5, 7, 11, 13};
    const auto result = DeleteElement::DeleteDuplicates(numbers);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(DeleteElement, DeleteDuplicateElements)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    const auto expected = std::vector<int>{2, 3, 5, 7, 11, 13};
    const auto result = DeleteElement::DeleteDuplicateElements(numbers);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(DeleteElement, DeleteSpecificElements)
{
    auto numbers = std::vector<int>{2, 3, 5, 5, 7, 11, 11, 11, 13};
    constexpr auto element = 11;
    const auto expected = std::vector<int>{2, 3, 5, 5, 7, 13};
    const auto result = DeleteElement::DeleteSpecificElements(numbers, element);
    EXPECT_EQ(expected, result);
}
