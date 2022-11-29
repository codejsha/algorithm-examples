#include "rectangle_intersection.h"

#include <algorithm>

auto RectangleIntersection::IntersectRectangle(const Rectangle& r1, const Rectangle& r2) -> Rectangle
{
    if (!IsIntersect(r1, r2))
    {
        return {0, 0, -1, -1};
    }
    return {
        std::max(r1.X, r2.X),
        std::max(r1.Y, r2.Y),
        std::min(r1.X + r1.Width, r2.X + r2.Width) - std::max(r1.X, r2.X),
        std::min(r1.Y + r1.Height, r2.Y + r2.Height) - std::max(r1.Y, r2.Y)};
}

auto RectangleIntersection::IsIntersect(const Rectangle& r1, const Rectangle& r2) -> bool
{
    return r1.X <= r2.X + r2.Width
           && r1.X + r1.Width >= r2.X
           && r1.Y <= r2.Y + r2.Height
           && r1.Y + r1.Height >= r2.Y;
}
