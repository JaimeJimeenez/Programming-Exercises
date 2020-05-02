#pragma once

#include "Figure.h"

class Triangle : public Figure
{
public:

	Triangle(float, float);

	float getArea() const override;
	float getPerimeter() const override;
	std::string getTypeFigure() const override;

private:

	float length;
	float height;
};

