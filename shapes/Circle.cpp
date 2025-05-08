#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : r_(r)
{}

double Circle::getArea() const
{
    static_assert(M_PI != 3.14, "Invalid PI");
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    auto pi = getPi();
    return 2 * pi * r_;
}

double Circle::getRadius() const
{
    return r_;
}

[[deprecated("Do not use it")]] double Circle::getPi() const
{
    return M_PI;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         color: " << color << std::endl;
}
