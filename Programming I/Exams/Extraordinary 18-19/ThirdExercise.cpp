#include <iostream>
#include <functional>
#include <vector>

float makeOperations(std::vector <float> actualNumbers, std::vector <char> actualOperands) {

	float result{ 0 };

	if (actualOperands.at(0) == '+') result = actualNumbers.at(0) + actualNumbers.at(1);
	else if (actualOperands.at(0) == '-') result = actualNumbers.at(0) + actualNumbers.at(1);
	else if (actualNumbers.at(0) == '*') result = actualNumbers.at(0) * actualNumbers.at(1);
	else if (actualNumbers.at(0) == '/') result = actualNumbers.at(0) / actualNumbers.at(1);

	for (int i{ 2 }; i < actualOperands.size(); i++) {
		if (actualOperands.at(i - 1) == '+') result += actualNumbers.at(i);
		else if (actualOperands.at(i - 1) == '-') result -= actualNumbers.at(i);
		else if (actualOperands.at(i - 1) == '*') result *= actualNumbers.at(i);
		else if (actualOperands.at(i - 1) == '/') result /= actualNumbers.at(i);
	}

	if (actualOperands.at(actualOperands.size() - 1) == '+') result += actualNumbers.at(actualNumbers.size() - 1);
	else if (actualOperands.at(actualOperands.size() - 1) == '-') result -= actualNumbers.at(actualNumbers.size() - 1);
	else if (actualOperands.at(actualOperands.size() - 1) == '*') result *= actualNumbers.at(actualNumbers.size() - 1);
	else if (actualOperands.at(actualOperands.size() - 1) == '/') result /= actualNumbers.at(actualNumbers.size() - 1);

	return result;
}

int main() {

	int cant;
	float imputNumber;
	char imputOperand;
	std::vector <float> allNumbers;
	std::vector <char> allOperands;

	std::cout << "How many numbers do you want to calculate? ";
	std::cin >> cant;
	
	std::cout << "Which are the numbers? ";
	for (int i{ 0 }; i < cant; i++) {
		std::cin >> imputNumber;
		allNumbers.push_back(imputNumber);
	}

	std::cout << "\nOperands: ";
	for (int i{ 0 }; i < cant - 1; i++) {
		std::cin >> imputOperand;
		allOperands.push_back(imputOperand);
	}

	float result{ makeOperations(allNumbers, allOperands) };
	std::cout << "Result: " << result;
	return 0;
}