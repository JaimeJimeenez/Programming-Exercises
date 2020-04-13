#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
	if (rows <= 0 || columns <= 0) throw std::string{ "Error: Rows and columns can not be 0 or less.\n" };
	this->rows = rows;
	this->columns = columns;
	this->imputMatrix = std::vector <std::vector <float>>(rows, std::vector <float>(columns));
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getColumns() const
{
	return columns;
}

float Matrix::getElement(int& rows, int& columns) const
{
	return imputMatrix.at(rows).at(columns);
}

void Matrix::setElement(int& rows, int& columns, float value)
{
	if (rows > this->rows || columns > this->columns) throw std::string{ "Error: Rows and columns can not be higher than the matrix.\n" };
	imputMatrix.at(rows).at(columns) = value;
}

Matrix Matrix::add(const Matrix& actualMatrix) const
{
	Matrix returnMatrix (rows, columns);
	
	if (rows != actualMatrix.getRows() || columns != actualMatrix.getColumns()) throw std::string{ "Error: The parameters must be the same.\n" };

	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j { 0 }; j < actualMatrix.getColumns(); j++) {
			returnMatrix.setElement(i, j, imputMatrix.at(i).at(j) + actualMatrix.getElement(i, j));
		}
	}

	return returnMatrix;
}

Matrix Matrix::substract(const Matrix& actualMatrix) const
{
	Matrix returnMatrix(rows, columns);

	if (rows != actualMatrix.getRows() || columns != actualMatrix.getColumns()) throw std::string{ "Error: The parameters must be the same.\n" };

	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			returnMatrix.setElement(i, j, imputMatrix.at(i).at(j) - actualMatrix.getElement(i, j));
		}
	}

	return returnMatrix;
}

Matrix Matrix::multiply(const Matrix& actualMatrix)
{
	if (rows != actualMatrix.getColumns() || columns != actualMatrix.getRows()) throw std::string{ "Error: Parameters not valid.\n" };

	for (int i{ 0 }; i < actualMatrix.getColumns(); i++) {
		for (int j{ 0 }; j < actualMatrix.getRows(); j++) {
			for (int k{ 0 }; k < actualMatrix.getColumns(); k++) {
				imputMatrix.at(i).at(j) += actualMatrix.getElement(i, k) * actualMatrix.getElement(k, j);
			}
		}
	}
}

std::vector<std::vector<float>> Matrix::generateMatrix()
{
	return imputMatrix;
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

std::istream& operator>>(std::istream& in, Matrix imputMatrix)
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

Matrix operator+(Matrix firstMatrix, const Matrix& secondMatrix)
{
	return firstMatrix.add(secondMatrix);
}

Matrix operator-(Matrix firstMatrix, const Matrix& secondMatrix)
{
	return firstMatrix.substract(secondMatrix);
}

Matrix operator*(Matrix firstMatrix, const Matrix& secondMatrix)
{
	return firstMatrix.multiply(secondMatrix);
}


