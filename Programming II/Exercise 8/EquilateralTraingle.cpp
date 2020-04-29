#include "EquilateralTriangle.h"
#include <math.h>

EquilateralTriangle::EquilateralTriangle(float length):Figure("Equilateral Triangle", (length * sqrt(pow(length / 2, 2) + pow(length, 2))), length * 3)
{
	if (length <= 0) throw std::string{ "Error: Imput parameter not valid.\n" };
}
