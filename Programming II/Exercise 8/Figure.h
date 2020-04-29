#pragma once

#include <string>

class Figure
{
public:

	Figure(std::string, float, float);

	std::string getTypeFigure() const;

	float getArea() const;
	float getPerimeter() const;

protected:

	std::string typeFigure;
	float area;
	float perimeter;

};

