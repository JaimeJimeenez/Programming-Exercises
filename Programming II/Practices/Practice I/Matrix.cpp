#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int columns)
{
	if (rows <= 0 || columns <= 0) throw std::string{ "Error: imput parameters not valid.\n" };
	this->rows = rows;
	this->columns = columns;
	imputMatrix = std::vector <std::vector <float>>(rows, std::vector<float>(columns));
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getColumns() const
{
	return columns;
}

float Matrix::getElement(int rows, int columns) const
{
	return imputMatrix.at(rows).at(columns);
}

void Matrix::setElement(int rows, int columns, float value)
{
	if (rows > getRows() || columns > getColumns()) throw std::string{ "Error: Imput parameters not valid.\n" };
	imputMatrix.at(rows).at(columns) = value;
}

std::vector<std::vector<float>> Matrix::generateMatrix() const
{
	return imputMatrix;
}

Matrix Matrix::add(Matrix otherMatrix) const
{
	if (rows != otherMatrix.getRows() || columns != otherMatrix.getColumns()) throw std::string{ "Error: Parameters of both matrix must be the same.\n" };

	Matrix result(rows, columns);
	for (int i{ 0 }; i < rows; i++) {
		for (int j{ 0 }; j < columns; j++) {
			result.setElement(i, j, imputMatrix.at(i).at(j) + otherMatrix.getElement(i, j));
		}
	}
	return result;
}

Matrix Matrix::multiply(const Matrix& otherMatrix) 
{
	if (rows != otherMatrix.getColumns() || columns != otherMatrix.getRows()) throw std::string { "Error: Parameters not valid.\n" };

	for (int i{ 0 }; i < otherMatrix.getColumns(); i++) {
		for (int j{ 0 }; j < otherMatrix.getRows(); j++) {
			for (int k{ 0 }; k < otherMatrix.getColumns(); k++) {
				imputMatrix.at(i).at(j) += otherMatrix.getElement(i, k) * otherMatrix.getElement(k, j);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Matrix& actualMatrix)
{
	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			out << actualMatrix.getElement(i, j) << " ";
		}
		out << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& actualMatrix)
{
	float value;
	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			in >> value;
			actualMatrix.setElement(i, j, value);
		}
	}
	return in;
}

Matrix operator+(Matrix firstMatrix, const Matrix& secondMatrix)
{
	return firstMatrix.add(secondMatrix);
}

Matrix operator*(Matrix firstMatrix, const Matrix& secondMatrix)
{
	return firstMatrix.multiply(secondMatrix);
}
