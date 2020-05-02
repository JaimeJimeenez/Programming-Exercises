#pragma once

#include <string>

class Figure
{
public:

	Figure();
	virtual ~Figure();

	virtual float getArea() const = 0;
	virtual float getPerimeter() const = 0;
	virtual std::string getTypeFigure() const;
};

