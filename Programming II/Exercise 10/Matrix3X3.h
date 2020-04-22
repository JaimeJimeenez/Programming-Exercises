#pragma once

#include "Matrix.h"

class Matrix3X3:public Matrix
{
public:

	Matrix3X3();

	float getDeterminant() const;

	Matrix3X3 getInverse();
	Matrix3X3 getTranspose();
	Matrix3X3 getAdjugate();

};
std::ostream& operator<<(std::ostream&, const Matrix3X3&);
std::istream& operator>>(std::istream&, Matrix3X3&);
