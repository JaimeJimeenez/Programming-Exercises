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

float& Matrix::getElement(int row, int column)
{
	if (row >= rows || column >= columns) throw std::string{ "Error: Parameters out of range.\n" };
	int position = row * columns + column;
	return data.at(position);
}

float Matrix::getDeterminant() const
{
	if (rows != columns) throw std::string{ "Error: Parameters must be the same.\n" };

	return 0;
}

std::ostream& operator<<(std::ostream& out, Matrix& actualMatrix)
{
	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			out << actualMatrix.getElement(i, j) << " ";
		}
		out << "\n";
	}
	out << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& imputMatrix)
{
	float value;
	for (int i{ 0 }; i < imputMatrix.getRows(); i++) {
		for (int j{ 0 }; j < imputMatrix.getColumns(); j++) {
			in >> value;
			imputMatrix.getElement(i, j) = value;
		}
	}
	return in;
}

Matrix operator+(Matrix& firstMatrix, Matrix& secondMatrix)
{
	if (firstMatrix.getRows() != secondMatrix.getRows() || firstMatrix.getColumns() != secondMatrix.getColumns()) throw std::string{ "Error: Parameters of both matrix must be the same.\n" };

	Matrix result(firstMatrix.getRows(), firstMatrix.getColumns());
	for (int i{ 0 }; i < firstMatrix.getRows(); i++) {
		for (int j{ 0 }; j < firstMatrix.getColumns(); j++) {
			result.getElement(i, j) = firstMatrix.getElement(i, j) + secondMatrix.getElement(i, j);
		}
	}
	return result;
}

Matrix operator-(Matrix& firstMatrix, Matrix& secondMatrix)
{
	if (firstMatrix.getRows() != secondMatrix.getRows() || firstMatrix.getColumns() != secondMatrix.getColumns()) throw std::string{ "Error: Parameters of both matrix must be the same.\n" };

	Matrix result(firstMatrix.getRows(), firstMatrix.getColumns());
	for (int i{ 0 }; i < firstMatrix.getRows(); i++) {
		for (int j{ 0 }; j < firstMatrix.getColumns(); j++) {
			result.getElement(i, j) = firstMatrix.getElement(i, j) - secondMatrix.getElement(i, j);
		}
	}
	return result;
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
				resultMatrix.getElement(i, j) = result;
			}
		}
	}
	return resultMatrix;
}