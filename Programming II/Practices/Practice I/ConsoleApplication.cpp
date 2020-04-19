#include <iostream>
#include "Matrix.h"

int main() {

	try {
		int imputRows;
		int imputColumns;

		//First Matrix
		std::cout << "Imput parameters for the matrix:";
		std::cin >> imputRows;
		std::cin >> imputColumns;
		Matrix firstMatrix(imputRows, imputColumns);
		std::cout << "Imput values for the matrix:\n";
		std::cin >> firstMatrix;

		//Second Matrix
		std::cout << "Imput parameters for the matrix:";
		std::cin >> imputRows;
		std::cin >> imputColumns;
		Matrix secondMatrix(imputRows, imputColumns);
		std::cout << "Imput values for the matrix:\n";
		std::cin >> secondMatrix;

		//Operations
		std::cout << "Sum:\n";
		Matrix sum = firstMatrix.add(secondMatrix);
		sum.print();
		std::cout << "Product:\n";
		Matrix product = firstMatrix.multiply(secondMatrix);
		product.print();
	}
	catch (const std::string& exception) {
		std::cout << exception;
	}
}