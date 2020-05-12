#pragma once
#include <vector>
#include <iostream>

class Matrix
{
	friend std::ostream& operator<<(std::ostream&, Matrix&);
public:

	Matrix();

	void fillMatrix(std::string);
	void solveMatrix();

	int getRows() const;
	int getColumns() const;
	int imputNumber();
	int getElement(int, int);

	std::vector <int> transformation(std::vector <char>);

private:

	int rows;
	int columns;
	std::vector <int> data;

};

