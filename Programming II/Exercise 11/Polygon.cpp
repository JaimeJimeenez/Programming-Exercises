#include "Polygon.h"
#include <math.h>

Polygon::Polygon(int sides, float length)
{
	if (sides <= 0 || length <= 0) throw std::string{ "Error: Imput parameters not valid.\n" };
	this->sides = sides;
	this->length = length;
}

float Polygon::getArea() const
{
	return (sides * length * sides / (2 * tan(180 / length))) / 2;
}

float Polygon::getPerimeter() const
{
	return sides * length;
}

std::string Polygon::getTypeFigure() const
{
	return "Polygon";
}

