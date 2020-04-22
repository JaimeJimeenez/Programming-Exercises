#include "Matrix3X3.h"

Matrix3X3::Matrix3X3() :Matrix(3, 3)
{
	this->rows = 3;
	this->columns = 3;
	data.resize(rows * columns, 0);
}

float Matrix3X3::getDeterminant() const
{
	return 0;
}

std::ostream& operator<<(std::ostream& out, const Matrix3X3& actualMatrix)
{
	out << "Matrix 3X3:\n";
	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			out << actualMatrix.getElement(i, j) << " ";
		}
		out << "\n";
	}

	return out;
}

std::istream& operator>>(std::istream& in, Matrix3X3& imputMatrix)
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


