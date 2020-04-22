#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int columns)
{
	if (rows <= 0 || columns <= 0) throw std::string{ "Error: Imput parameters not valid.\n " };
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
	if (row >= rows || column >= columns) throw std::string{ "Error: Parameters out of range.\n" };
	int position = row * columns + column;
	return data.at(position);
}

void Matrix::setElement(int row, int column, float value)
{
	if (row >= rows || column >= columns) throw std::string{ "Error: Parameters out of range.\n" };
	int position = row * columns + column;
	data.at(position) = value;
}

std::ostream& operator<<(std::ostream& out, const Matrix& actualMatrix)
{
	out << "Matrix:\n";
	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			out << actualMatrix.getElement(i, j) << " ";
		}
		out << "\n";
	}
	return out;
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

Matrix operator+(const Matrix& firstOperand, const Matrix& secondOperand)
{
	if (firstOperand.getRows() != secondOperand.getRows() || firstOperand.getColumns() != secondOperand.getColumns()) throw std::string{ "Error: Parameters must be the same.\n" };

	Matrix result(firstOperand.getRows(), firstOperand.getColumns());
	for (int i{ 0 }; i < firstOperand.getRows(); i++) {
		for (int j{ 0 }; j < firstOperand.getColumns(); j++) {
			result.setElement(i, j, firstOperand.getElement(i, j) + secondOperand.getElement(i, j));
		}
	}

	return result;
}

Matrix operator-(const Matrix& firstOperand, const Matrix& secondOperand)
{
	if (firstOperand.getRows() != secondOperand.getRows() || firstOperand.getColumns() != secondOperand.getColumns()) throw std::string{ "Error: Parameters must be the same.\n" };

	Matrix result(firstOperand.getRows(), firstOperand.getColumns());
	for (int i{ 0 }; i < firstOperand.getRows(); i++) {
		for (int j{ 0 }; j < firstOperand.getColumns(); j++) {
			result.setElement(i, j, firstOperand.getElement(i, j) - secondOperand.getElement(i, j));
		}
	}

	return result;;
}

Matrix operator*(Matrix& firstMatrix, Matrix& secondMatrix)
{
	if (firstMatrix.getColumns() != secondMatrix.getRows()) throw std::string{ "Error: Parameters not valid.\n" };

	Matrix resultMatrix{ firstMatrix.getRows(), secondMatrix.getColumns() };

	for (int i{ 0 }; i < firstMatrix.getRows(); i++) {
		for (int j{ 0 }; j < secondMatrix.getColumns(); j++) {
			float result{ 0 };
			for (int k{ 0 }; k < secondMatrix.getColumns(); k++) {
				result += firstMatrix.getElement(i, j) * secondMatrix.getElement(k, j);
				resultMatrix.setElement(i, j, result);
			}
		}
	}
	return resultMatrix;
}
