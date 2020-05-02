#pragma once
#include <string>

#include "Figure.h"

class Polygon : public Figure
{
public:

	Polygon(int, float);

	float getArea() const override;
	float getPerimeter() const override;
	std::string getTypeFigure() const override;

private:
	float length;
	int sides;
};

