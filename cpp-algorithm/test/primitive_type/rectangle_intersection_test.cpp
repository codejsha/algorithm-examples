#include "rectangle_intersection.h"

#include <gtest/gtest.h>

TEST(RectangleIntersectionTest, Simple1)
{
    constexpr auto expected = RectangleIntersection::Rectangle{0, 0, -1, -1};
    constexpr auto rect1 = RectangleIntersection::Rectangle{1, 2, 3, 4};
    constexpr auto rect2 = RectangleIntersection::Rectangle{5, 3, 2, 4};

    const auto result = IntersectRectangle(rect1, rect2);
    ASSERT_EQ(expected.X, result.X);
    ASSERT_EQ(expected.Y, result.Y);
    ASSERT_EQ(expected.Width, result.Width);
    ASSERT_EQ(expected.Height, result.Height);
}
