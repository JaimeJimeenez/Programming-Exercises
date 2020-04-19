#pragma once

#include <iostream>
#include <vector>

class Matrix
{
public:

	Matrix(int, int);

	int getRows() const;
	int getColumns() const;
	float& getElement(int, int);

private:
	
	int rows;
	int columns;
	std::vector <float> data;

};
std::ostream& operator<<(std::ostream&, Matrix&);
std::istream& operator>>(std::istream&, Matrix&);

Matrix operator+(Matrix&, Matrix&);
Matrix operator-(Matrix&, Matrix&);
Matrix operator*(Matrix&, Matrix&);

