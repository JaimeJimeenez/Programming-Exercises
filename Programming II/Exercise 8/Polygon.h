#pragma once

#include "Figure.h"

class Polygon : public Figure
{
public:

	Polygon(int, float);

private:

	int sides;
	float length;

};

