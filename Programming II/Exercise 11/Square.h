#pragma once

#include "Figure.h"

class Square : public Figure
{
public:
	Square(float);

	float getArea() const override;
	float getPerimeter() const override;
	std::string getTypeFigure() const override;

private:
	float length;
};

