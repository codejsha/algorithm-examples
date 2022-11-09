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

    Rectangle IntersectRectangle(const Rectangle& r1, const Rectangle& r2);

    bool IsIntersect(const Rectangle& r1, const Rectangle& r2);
}

#endif
