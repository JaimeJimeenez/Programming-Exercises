#include <iostream>
#include "Operands.h"
#include "Matrix.h"

int main() {

	try
	{
		int imputRows;
		int imputColumns;
		int intFirstValue;
		int intSecondValue;
		float floatFirstValue;
		float floatSecondValue;

		std::cout << "Imput parameters for the Matrix: ";
		std::cin >> imputRows >> imputColumns;
		Matrix firstMatrix(imputRows, imputColumns);
		std::cout << "Imput values for the Matrix:\n";
		std::cin >> firstMatrix;

		std::cout << "Imput parameters for the Matrix: ";
		std::cin >> imputRows >> imputColumns;
		Matrix secondMatrix(imputRows, imputColumns);
		std::cout << "Imput values for the Matrix:\n";
		std::cin >> secondMatrix;

		std::cout << "Imput int values: ";
		std::cin >> intFirstValue >> intSecondValue;

		std::cout << "Imput float values: ";
		std::cin >> floatFirstValue >> floatSecondValue;

		std::cout << "\nOperations:\n------------\n";

		std::cout << "\nSum: \n";
		std::cout << add<Matrix>(firstMatrix, secondMatrix);
		std::cout << "Int: " << add<int>(intFirstValue, intSecondValue) << "\n";
		std::cout << "Float: " << add<float>(floatFirstValue, floatSecondValue) << "\n";

		std::cout << "\nSubstract:\n";
		std::cout << substract<Matrix>(firstMatrix, secondMatrix);
		std::cout << "Int: " << substract(intFirstValue, intSecondValue) << "\n";
		std::cout << "Float: " << substract(floatFirstValue, floatSecondValue) << "\n";

		std::cout << "\nProduct:\n";
		std::cout << multiply<Matrix>(firstMatrix, secondMatrix);
		std::cout << "Int: " << multiply<int>(intFirstValue, intSecondValue) << "\n";
		std::cout << "Float: " << multiply<float>(floatFirstValue, floatSecondValue) << "\n";

	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}

	return 0;
}