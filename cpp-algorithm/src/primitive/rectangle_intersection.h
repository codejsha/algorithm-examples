#ifndef CPP_ALGORITHM_RECTANGLE_INTERSECTION_H
#define CPP_ALGORITHM_RECTANGLE_INTERSECTION_H

#include <algorithm>

namespace RectangleIntersection
{
    struct Rectangle
    {
        int X;
        int Y;
        int Width;
        int Height;
    };

    /**
     * \brief Check if two rectangles intersect.
     * \param r1 rectangle 1
     * \param r2 rectangle 2
     * \return result
     */
    Rectangle IntersectRectangle(
        const Rectangle& r1,
        const Rectangle& r2);

    /**
     * \brief Check the intersection of two rectangles.
     * \param r1 rectangle 1
     * \param r2 rectangle 2
     * \return Whether two rectangles intersect
     */
    bool IsIntersect(
        const Rectangle& r1,
        const Rectangle& r2);
}

// ----------------------------------------------------------------------------
inline RectangleIntersection::Rectangle RectangleIntersection::IntersectRectangle(
    const Rectangle& r1,
    const Rectangle& r2)
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

// ----------------------------------------------------------------------------
inline bool RectangleIntersection::IsIntersect(
    const Rectangle& r1,
    const Rectangle& r2)
{
    return r1.X <= r2.X + r2.Width
           && r1.X + r1.Width >= r2.X
           && r1.Y <= r2.Y + r2.Height
           && r1.Y + r1.Height >= r2.Y;
}

#endif
