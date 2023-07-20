#ifndef CPP_ALGORITHM_RECTANGLE_INTERSECTION_H
#define CPP_ALGORITHM_RECTANGLE_INTERSECTION_H

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
    auto IntersectRectangle(const Rectangle& r1, const Rectangle& r2) -> Rectangle;

    /**
     * \brief Check the intersection of two rectangles.
     * \param r1 rectangle 1
     * \param r2 rectangle 2
     * \return Whether two rectangles intersect
     */
    auto IsIntersect(const Rectangle& r1, const Rectangle& r2) -> bool;
}

#endif
