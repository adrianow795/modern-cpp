#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(double x);
    Square(const Square & other) = default;

    double getArea();
    double getPerimeter();
    void print();

private:
    double getY() = delete;
    
};
