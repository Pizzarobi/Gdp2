#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    float height;
    float width;
    static int number;
public:
    Rectangle(const float pHeight, const float pWidth);
    Rectangle(const Rectangle& rect);
    float getHeight() const;
    float getWidth() const;
    static int getNumber();
    void setHeight(const float pHeight);
    void setWidth(const float pWidth);
    float compArea() const;
};

#endif
