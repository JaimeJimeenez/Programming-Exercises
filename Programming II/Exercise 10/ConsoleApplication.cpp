#include <iostream>
#include "Matrix.h"
#include "DiagonalMatrix.h"
#include "Matrix3X3.h"
#include "Matrix2X2.h"

int main() {

	try
	{
		int imputRows;
		int imputColumns;

		//Diagonal Matrix
		std::cout << "Imput parameters for the Diagonal Matrix: ";
		std::cin >> imputRows >> imputColumns;
		DiagonalMatrix newDiagonalMatrix(3, 3);
		std::cout << "Imput values for the Diagonal Matrix ( " << imputRows << " values ):\n";
		std::cin >> newDiagonalMatrix;
		std::cout << newDiagonalMatrix;
		std::cout << "Determinant: " << newDiagonalMatrix.getDeterminant() << "\n";

		//Matrix3X3
		Matrix3X3 newMatrix3X3;
		std::cout << "Values for the Matrix 3X3:\n";
		std::cin >> newMatrix3X3;
		std::cout << "Determinant: " << newMatrix3X3.getDeterminant() << "\n";

		//Matrix2X2
		Matrix2X2 newMatrix2X2;
		std::cout << "Values for the Matrix 2X2:\n";
		std::cin >> newMatrix2X2;
		std::cout << "Determinant: " << newMatrix2X2.getDeterminant() << "\n";

	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}
	

	return 0;
}