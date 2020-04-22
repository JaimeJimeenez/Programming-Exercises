#pragma once

#include <iostream>
#include "Matrix.h"

class DiagonalMatrix : public Matrix
{
public:

	DiagonalMatrix(int, int);

	float getDeterminant() const;

	DiagonalMatrix getInverse();
	DiagonalMatrix getTraspose();
	DiagonalMatrix getAdjugate();

};
std::ostream& operator<<(std::ostream&, const DiagonalMatrix&);
std::istream& operator>>(std::istream&, DiagonalMatrix&);
