#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle() = delete;
    double getArea() const;
    double getPerimeter() const;
    double getRadius() const;
    void print() const;

private:
    

    double r_;
};
