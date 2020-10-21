#include "utility.h"

bool df::positionsIntersect(Vector p1, Vector p2)
{
    if (abs(p1.getX() - p2.getX()) <= 1 && abs(p1.getY() - p2.getY()) <= 1)
    {
        return true;
    }
    return false;
}
