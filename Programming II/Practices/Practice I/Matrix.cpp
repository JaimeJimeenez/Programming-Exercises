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

float Matrix::getElement(int row, int column)
{
	if (row > rows || column > columns) throw std::string{ "Error: Parameters out of range.\n" };
	int position = row * columns + column;
	return data.at(position);
}

void Matrix::setElement(int row, int column, float value)
{
	if (row > rows || column > columns) throw std::string{ "Error: Parameters out of range.\n" };
	int position = row * columns + column;
	data.at(position) = value;
}

void Matrix::print() const
{
	std::cout << "Matrix:\n";
	for (int i{ 0 }; i < rows; i++) {
		for (int j{ 0 }; j < columns; j++) {
			int position = i * columns + j;
			std::cout << data.at(position) << " ";
		}
		std::cout << "\n";
	}
}

Matrix Matrix::add(Matrix& otherMatrix)
{
	if (rows != otherMatrix.getRows() || columns != otherMatrix.getColumns()) throw std::string{ "Error: Parameters must be the same.\n" };

	Matrix result(rows, columns);
	for (int i{ 0 }; i < otherMatrix.getRows(); i++) {
		for (int j{ 0 }; j < otherMatrix.getColumns(); j++) {
			int position = i * columns + j;
			result.setElement(i, j, data.at(position) + otherMatrix.getElement(i, j));
		}
	}
	return result;
}

Matrix Matrix::multiply(Matrix& otherMatrix)
{
	if (rows != otherMatrix.getColumns() || columns != otherMatrix.getRows()) throw std::string{ "Error: Parameters must be the same.\n" };
	
	Matrix result(rows, columns);
	for (int i{ 0 }; i < otherMatrix.getRows(); i++) {
		for (int j{ 0 }; j < otherMatrix.getColumns(); j++) {
			float result{ 0 };
			for (int k{ 0 }; k < otherMatrix.getColumns(); k++) {
				result += otherMatrix.getElement(i, j) * otherMatrix.getElement(k, j);
			}
		}
	}
	return result;
}



std::istream& operator>>(std::istream& in, Matrix& imputMatrix)
{
	float value;
	for (int i{ 0 }; i < imputMatrix.getRows(); i++) {
		for (int j{ 0 }; j < imputMatrix.getColumns(); j++) {
			in >> value;
			imputMatrix.setElement(i, j, value);
		}
	}
	return in;
}
