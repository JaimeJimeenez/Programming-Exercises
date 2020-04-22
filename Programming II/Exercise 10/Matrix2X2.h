#pragma once

#include "Matrix.h"

class Matrix2X2:public Matrix
{
public:

	Matrix2X2();

	float getDeterminant() const;

	Matrix2X2 getInverse() const;
	Matrix getTranspose() const;
	Matrix getAdjugate() const;

};
std::ostream& operator<<(std::ostream&, const Matrix2X2&);
std::istream& operator>>(std::istream&, Matrix2X2&);
