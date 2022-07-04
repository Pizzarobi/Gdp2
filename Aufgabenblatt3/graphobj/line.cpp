#include <iostream>
#include "line.h"

Line::Line(const int pXCoord, const int pYCoord, const int pEndX, const int pEndY): GraphObj(pXCoord, pYCoord)
{
    endX = pEndX;
    endY = pEndY;
}

std::vector<int> Line::getEndPoint() const
{
    return { endX, endY };
}

double Line::length() const
{
    // please add it yourself
    return 0;
}

double Line::area() const
{
    return 0;
}

void Line::draw() const
{
    std::cout << "line drawn\n";
}

