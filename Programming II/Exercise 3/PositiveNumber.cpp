#include "PositiveNumber.h"

PositiveNumber::PositiveNumber(float number)
{
	if (number < 0) throw std::string{ "Error: The number must be positive.\n" };
	this->number = number;
}

float PositiveNumber::getNumber() const
{
	return number;
}

void PositiveNumber::setNumber(float& value)
{
	if (value < 0) throw std::string{ "Error: The value must be positive.\n" };
	number = value;
}

float PositiveNumber::divideBy(float number)
{
	if (number <= 0) throw std::string{ "Error: The other number must be positive and higher than 0.\n" };
	return this->number / number;
}

float PositiveNumber::addBy(float number)
{
	if (this->number + number < 0) throw std::string{ "Error: The result must be positive.\n" };
	return this->number + number;
}

float PositiveNumber::multiplyBy(float number)
{
	if (number < 0) throw std::string{ "Error: The other number must be positive.\n" };
	return this->number * number;
}
