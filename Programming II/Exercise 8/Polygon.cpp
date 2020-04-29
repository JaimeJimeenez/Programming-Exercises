#include "Polygon.h"
#include <math.h>

Polygon::Polygon(int sides, float length):Figure("Polygon", (sides * length * sides / (2 * tan(180 / length)))/2, sides * length)
{
	if (sides <= 0 || length <= 0) throw std::string{ "Error: Imput parameters not valid.\n" };
	this->sides = sides;
	this->length = length;
}
