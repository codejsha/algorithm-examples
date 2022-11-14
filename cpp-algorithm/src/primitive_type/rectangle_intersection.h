#ifndef CPP_ALGORITHM_RECTANGLE_INTERSECTION_H
#define CPP_ALGORITHM_RECTANGLE_INTERSECTION_H

namespace RectangleIntersection
{
    /// @brief Rectangle structure.
    struct Rectangle
    {
        int X;
        int Y;
        int Width;
        int Height;
    };

    /// @brief Check if two rectangles intersect.
    /// @param r1 rectangle 1
    /// @param r2 rectangle 2
    /// @return result
    Rectangle IntersectRectangle(const Rectangle& r1, const Rectangle& r2);

    /// @brief Check the intersection of two rectangles.
    /// @param r1 rectangle 1
    /// @param r2 rectangle 2
    /// @return Whether two rectangles intersect
    bool IsIntersect(const Rectangle& r1, const Rectangle& r2);
}

#endif
