#pragma once
#include <iostream>

class PositiveNumber
{
public:

	PositiveNumber(float);

	float getNumber() const;
	void setNumber(float&);

	float divideBy(float);
	float addBy(float);
	float multiplyBy(float);

private:
	float number;
};

