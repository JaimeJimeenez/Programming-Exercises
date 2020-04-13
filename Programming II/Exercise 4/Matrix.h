#pragma once
#include <iostream>
#include <vector>

class Matrix
{
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
public:

	Matrix(int, int);

	int getRows() const;
	int getColumns() const;

	float getElement(int&, int&) const;
	void setElement(int&, int&, float);

	Matrix add(const Matrix&) const;
	Matrix substract(const Matrix&) const;
	Matrix multiply(const Matrix&);

	std::vector <std::vector <float>> generateMatrix();

private:

	int rows;
	int columns;
	std::vector <std::vector <float>> imputMatrix;
};
std::istream& operator>>(std::istream&, Matrix);
Matrix operator+(Matrix, const Matrix&);
Matrix operator-(Matrix, const Matrix&);
Matrix operator*(Matrix, const Matrix&);
