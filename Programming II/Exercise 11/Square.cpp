#include "Square.h"

#include <iostream>

Square::Square(float length)
{
	if (length <= 0) throw std::string{ "Error: Imput parameter not valid.\n" };
	this->length = length;
}

float Square::getArea() const
{
	return length * length;
}

float Square::getPerimeter() const
{
	return length * 4;
}

std::string Square::getTypeFigure() const
{
	return "Square";
}
