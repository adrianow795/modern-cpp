#pragma once

#include "Shape.hpp"

class Circle final: public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle() = delete;
    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    

    double r_;
};
