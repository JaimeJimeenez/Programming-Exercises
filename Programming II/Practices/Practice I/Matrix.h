#pragma once

#include <iostream>
#include <vector>

class Matrix {
	
public:

	Matrix(int, int); 

	int getRows() const;
	int getColumns() const;
	float getElement(int, int) ;

	void setElement(int, int, float);

	void print() const;

	Matrix add(Matrix&);
	Matrix multiply(Matrix&);

private:

	int rows;
	int columns;
	std::vector <float> data;
};

std::istream& operator>>(std::istream&, Matrix&);