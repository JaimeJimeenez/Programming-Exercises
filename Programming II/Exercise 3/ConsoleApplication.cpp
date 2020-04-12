#include <iostream>
#include "PositiveNumber.h"

int main() {

	try
	{
		float number;
		float otherNumber;

		std::cout << "Introduce a positive number: ";
		std::cin >> number;

		PositiveNumber newNumber{ number };

		std::cout << "Introduce other number: ";
		std::cin >> otherNumber;
		std::cout << "Result of the division: " << newNumber.divideBy(otherNumber) << "\n";
		std::cout << "Result of the product: " << newNumber.multiplyBy(otherNumber) << "\n";
		std::cout << "Result of the sum: " << newNumber.addBy(otherNumber) << "\n";
	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}

	return 0;
}