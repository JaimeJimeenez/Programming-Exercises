#pragma once

#include <iostream>
#include <vector>

class Matrix
{
public:

	Matrix(int, int);

	int getRows() const;
	int getColumns() const;

	float getElement(int, int) const;
	void setElement(int, int, float);

protected:

	int rows;
	int columns;
	std::vector <float> data;

};

