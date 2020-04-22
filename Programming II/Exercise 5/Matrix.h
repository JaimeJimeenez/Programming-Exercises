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

private:

	int rows;
	int columns;
	std::vector <float> data;

};
std::ostream& operator<<(std::ostream&, const Matrix&);
std::istream& operator>>(std::istream&, Matrix&);

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(Matrix&, Matrix&);