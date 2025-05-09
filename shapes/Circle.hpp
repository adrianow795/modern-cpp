#pragma once

#include "Shape.hpp"

class  alignas(1)  Circle  final: public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle() = delete;
    Circle(Color c) : Shape(c){};
    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;
    [[deprecated("Do not use it")]]double getPi() const;

private:
    

    double r_ = 1.0;
};
