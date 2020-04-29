#include "Square.h"

Square::Square(float length) :Figure("Square", pow(length, 2), length * 4)
{
	if (length <= 0) throw std::string{ "Error: Imput parameter not valid.\n" };
}
