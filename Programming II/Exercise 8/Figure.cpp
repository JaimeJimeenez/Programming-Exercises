#include "Figure.h"

Figure::Figure(std::string typeFigure, float area, float perimeter)
{
	this->typeFigure = typeFigure;
	this->area = area;
	this->perimeter = perimeter;
}

std::string Figure::getTypeFigure() const
{
	return typeFigure;
}

float Figure::getArea() const
{
	return area;
}

float Figure::getPerimeter() const
{
	return perimeter;
}

