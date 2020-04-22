#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(int rows, int columns):Matrix(rows, columns)
{
	if (rows != columns) throw std::string{ "Error: Parameters must be the same.\n" };
	this->rows = rows;
	this->columns = columns;
	data.resize(rows * columns, 0);
}

float DiagonalMatrix::getDeterminant() const
{
	float result{ 1 };
	for (int i{ 0 }; i < rows; i++) {
		for (int j { 0 }; j < columns; j++) {
			if (i == j) {
				int position = i * columns + j;
				result *= data.at(position);
			}
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const DiagonalMatrix& DiagonalM)
{
	out << "Diagonal Matrix:\n";
	for (int i { 0 }; i < DiagonalM.getRows(); i++) {
		for (int j{ 0 }; j < DiagonalM.getColumns(); j++) {
			out << DiagonalM.getElement(i, j) << " ";
		}
		out << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, DiagonalMatrix& imputDiagonal)
{
	float value;
	for (int i { 0 }; i < imputDiagonal.getRows(); i++) {
		for (int j{ 0 }; j < imputDiagonal.getColumns(); j++) {
			if (i == j) {
				in >> value;
				imputDiagonal.setElement(i, j, value);
			}
		}
	}
	return in;
}
