#include <iostream>
#include "rectangle.h"

int Rectangle::number = 0;

Rectangle::Rectangle(const float pHeight, const float pWidth)
{
    number++;
    setHeight(pHeight);
    setWidth(pWidth);
}

Rectangle::Rectangle(const Rectangle& rect):
    Rectangle(rect.height, rect.width)
{
}

float Rectangle::compArea() const
{
    return height * width;
}

float Rectangle::getHeight() const
{
    return height;
}

float Rectangle::getWidth() const
{
    return width;
}

int Rectangle::getNumber()
{
    return number;
}

void Rectangle::setHeight(const float pHeight)
{
    if (pHeight > 0)
        height = pHeight;
    else
        height = 1;
}

void Rectangle::setWidth(const float pWidth)
{
    if (pWidth > 0)
        width = pWidth;
    else
        width = 1;
}

int main()
{
    Rectangle rectA(2.5, 10.0);
    std::cout << "Height: " << rectA.getHeight() << '\n';
    std::cout << "Width:  " << rectA.getWidth() << '\n';
    std::cout << "Area:   " << rectA.compArea() << "\n\n";
    std::cout << "Number: " << Rectangle::getNumber() << "\n\n";
    Rectangle rectB(7.5, 10.0);
    Rectangle rectC = rectB;
    std::cout << "Height: " << rectC.getHeight() << '\n';
    std::cout << "Width:  " << rectC.getWidth() << "\n\n";
    std::cout << "Number: " << Rectangle::getNumber() << '\n';
}

