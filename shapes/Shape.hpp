#pragma once

enum class Color : unsigned char 
{
    ORANGE,
    BLUE,
    GREEN
};

class Shape
{
public:
    Color color = Color::BLUE;
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
