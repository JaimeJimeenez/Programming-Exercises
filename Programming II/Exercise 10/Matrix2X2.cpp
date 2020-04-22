#include "Matrix2X2.h"

Matrix2X2::Matrix2X2(): Matrix(2, 2)
{
	this->rows = 2;
	this->columns = 2;
	data.resize(rows * columns, 0);
}

float Matrix2X2::getDeterminant() const
{
	return getElement(0, 0) * getElement(1, 1) - getElement(0, 1) * getElement(1, 0);
}

std::ostream& operator<<(std::ostream& out, const Matrix2X2& actualMatrix)
{
	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			out << actualMatrix.getElement(i, j) << " "; 
		}
		out << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Matrix2X2& imputMatrix)
{
	float value;
	for(int i{ 0 }; i < imputMatrix.getRows(); i++) {
		for (int j{ 0 }; j < imputMatrix.getColumns(); j++) {
			in >> value;
			imputMatrix.setElement(i, j, value);
		}
	}
	return in;
}
