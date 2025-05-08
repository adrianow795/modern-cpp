#pragma once
#include <iostream>

enum class Color : unsigned char 
{
    ORANGE,
    BLUE,
    GREEN
};

std::ostream& operator <<(std::ostream& os, Color c);


class Shape
{
public:
    Color color = Color::BLUE;
    Shape(Color c) : color(c){};
    Shape() = default;
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
