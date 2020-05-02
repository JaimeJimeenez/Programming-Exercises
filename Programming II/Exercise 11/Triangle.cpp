#include "Triangle.h"

#include <iostream>

Triangle::Triangle(float length, float height)
{
	if (length <= 0 || height <= 0) throw std::string{ "Error: Imput parameters not valid.\n" };
	this->length = length;
	this->height = height;
}

float Triangle::getArea() const
{
	return ((length * height) / 2);
}

float Triangle::getPerimeter() const
{
	return length * 3;
}

std::string Triangle::getTypeFigure() const
{
	return "Triangle";
}
