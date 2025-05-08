#include "Shape.hpp"
#include <iostream>

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

std::ostream& operator <<(std::ostream& os, Color c)
{
    if(c == Color::BLUE)
    {
        os << "BLUE";
    }
    else if(c == Color::GREEN)
    {
        os << "GREEN";
    }
    else if(c == Color::ORANGE)
    {
        os << "ORANGE";
    }
    return os;
}