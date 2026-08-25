#include "order_element.h"

#include <gtest/gtest.h>

#include <algorithm>

namespace
{
    /// \brief Checks that every even element appears before every odd element.
    bool IsEvenOddPartitioned(const std::vector<int>& arr)
    {
        const auto first_odd = std::find_if(
            arr.begin(), arr.end(), [](const int n) { return n % 2 != 0; });
        return std::all_of(
            first_odd, arr.end(), [](const int n) { return n % 2 != 0; });
    }

    /// \brief Checks the zigzag property A[0] <= A[1] >= A[2] <= A[3] >= ...
    bool IsZigzag(const std::vector<int>& arr)
    {
        for (int i = 1; i < static_cast<int>(arr.size()); ++i)
        {
            if ((i % 2 == 1 && arr[i - 1] > arr[i]) || (i % 2 == 0 && arr[i - 1] < arr[i]))
            {
                return false;
            }
        }
        return true;
    }
}

GTEST_TEST(OrderElement, EvenOdd)
{
    const auto input = std::vector<int>{1, 2, 3, 4, 5};

    auto arr = input;
    OrderElement::EvenOdd(arr);

    EXPECT_TRUE(IsEvenOddPartitioned(arr));
    EXPECT_TRUE(std::is_permutation(arr.begin(), arr.end(), input.begin()));
}

GTEST_TEST(OrderElement, EvenOddAllEven)
{
    const auto input = std::vector<int>{2, 4, 6, 8};

    auto arr = input;
    OrderElement::EvenOdd(arr);

    EXPECT_TRUE(IsEvenOddPartitioned(arr));
    EXPECT_TRUE(std::is_permutation(arr.begin(), arr.end(), input.begin()));
}

GTEST_TEST(OrderElement, EvenOddAllOdd)
{
    const auto input = std::vector<int>{1, 3, 5, 7};

    auto arr = input;
    OrderElement::EvenOdd(arr);

    EXPECT_TRUE(IsEvenOddPartitioned(arr));
    EXPECT_TRUE(std::is_permutation(arr.begin(), arr.end(), input.begin()));
}

GTEST_TEST(OrderElement, EvenOddEmpty)
{
    auto arr = std::vector<int>{};
    OrderElement::EvenOdd(arr);
    EXPECT_TRUE(arr.empty());
}

GTEST_TEST(OrderElement, EvenOddSingleElement)
{
    auto arr = std::vector<int>{1};
    OrderElement::EvenOdd(arr);
    EXPECT_EQ(std::vector<int>{1}, arr);
}

GTEST_TEST(OrderElement, Rearrange)
{
    const auto input = std::vector<int>{3, 1, 2, 5, 4};
    const auto expected = std::vector<int>{1, 3, 2, 5, 4};

    auto arr = input;
    const auto result = OrderElement::Rearrange(arr);

    EXPECT_EQ(expected, result);
    EXPECT_TRUE(IsZigzag(result));
    EXPECT_TRUE(std::is_permutation(result.begin(), result.end(), input.begin()));
}

GTEST_TEST(OrderElement, RearrangeSortedInput)
{
    const auto input = std::vector<int>{1, 2, 3, 4, 5};
    const auto expected = std::vector<int>{1, 3, 2, 5, 4};

    auto arr = input;
    const auto result = OrderElement::Rearrange(arr);

    EXPECT_EQ(expected, result);
    EXPECT_TRUE(IsZigzag(result));
}

GTEST_TEST(OrderElement, RearrangeEmpty)
{
    auto arr = std::vector<int>{};
    const auto result = OrderElement::Rearrange(arr);
    EXPECT_TRUE(result.empty());
}

GTEST_TEST(OrderElement, RearrangeSingleElement)
{
    auto arr = std::vector<int>{1};
    const auto result = OrderElement::Rearrange(arr);
    EXPECT_EQ(std::vector<int>{1}, result);
}
