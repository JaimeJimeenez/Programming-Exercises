#include <iostream>
#include "Matrix.h"

int main() {

	try
	{
		
		Matrix imputMatrix(3, 3);
		Matrix secondMatrix(3, 3);
		std::cout << "Imput Matrix:\n";
		std::cin >> imputMatrix;
		std::cout << "Introduce another Matrix:\n";
		std::cin >> secondMatrix;
		std::cout << "Result of the sum:\n" << imputMatrix + secondMatrix;
		std::cout << "Result of the product:\n" << imputMatrix * secondMatrix;
	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}

	return 0;
}