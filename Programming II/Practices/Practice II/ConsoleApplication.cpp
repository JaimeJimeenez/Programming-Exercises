#include <iostream>
#include "Matrix.h"

int main() {

	try
	{
		int imputRows;
		int imputColumns;

		//First Matrix
		std::cout << "Imput the number of rows and columns: ";
		std::cin >> imputRows;
		std::cin >> imputColumns;
		Matrix newMatrix(imputRows, imputColumns);
		std::cout << "Imput the values of the matrix:\n";
		std::cin >> newMatrix;
		std::cout << "Matrix: \n" << newMatrix;

		//Second Matrix
		std::cout << "Imput the number of rows and columns: ";
		std::cin >> imputRows;
		std::cin >> imputColumns;
		Matrix otherMatrix(imputRows, imputColumns);
		std::cout << "Imput the values of the matrix:\n";
		std::cin >> otherMatrix;
		std::cout << "Matrix: \n" << otherMatrix;

		//Operations
		std::cout << "Sum:\n";
		Matrix sum = newMatrix + otherMatrix;
		std::cout << sum;
		std::cout << "Substract:\n";
		Matrix substract = newMatrix - otherMatrix;
		std::cout << substract;
		std::cout << "Product:\n";
		Matrix product = newMatrix * otherMatrix;
		std::cout << product;
	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}
}