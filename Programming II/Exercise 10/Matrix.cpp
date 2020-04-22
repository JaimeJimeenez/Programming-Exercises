#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
	if (rows <= 0 || columns <= 0) throw std::string{ "Error: Imput parameters not valid.\n" };
	this->rows = rows;
	this->columns = columns;
	data.resize(rows * columns, 0);
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getColumns() const
{
	return columns;
}

float Matrix::getElement(int row, int column) const
{
	if (row >= rows || column >= columns) throw std::string{ "Error: Paramteres out of range.\n" };
	int position = row * columns + column;
	return data.at(position);
}

void Matrix::setElement(int row, int column, float value)
{
	int position = row * columns + column;
	data.at(position) = value;
}
