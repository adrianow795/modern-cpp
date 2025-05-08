#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(Color c) : Shape(c){};
    Rectangle()= delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getX() const;
    double getY() const;
    void print() const override;

private:
    

    double x_ = 1.0;
    double y_ = 2.0;
};
