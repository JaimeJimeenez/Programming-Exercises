#include <iostream>
#include <functional>

std::function <float(float, float)> add = [](float firstNumber, float secondNumber) {
	return firstNumber + secondNumber;
};

std::function <float(float, float)> substract = [](float firstNumber, float secondNumber) {
	return firstNumber - secondNumber;
};

std::function <float(float, float)> multiply = [](float firstNumber, float secondNumber) {
	return firstNumber * secondNumber;
};

std::function <float(float, float)> divide = [](float firstNumber, float secondNumber) {
	return firstNumber / secondNumber;
};

int main() {

	int option;
	float firstNumber;
	float secondNumber;
	float result;

	std::cout << "Introduce 2 numbers to operate: ";
	std::cin >> firstNumber >> secondNumber;

	std::cout << "1. Add the numbers.\n";
	std::cout << "2. Substract the numbers.\n";
	std::cout << "3. Multiply the numbers.\n";
	std::cout << "4. Divide the numbers.\n";
	std::cout << "5. Exit.\n";
	std::cin >> option;

	switch (option) {
	case 1: result = add(firstNumber, secondNumber);
		std::cout << "Result: " << result;
		break;

	case 2: result = substract(firstNumber, secondNumber);
		std::cout << "Result: " << result;
		break;

	case 3: result = multiply(firstNumber, secondNumber);
		std::cout << "Result: " << result;
		break;

	case 4: result = divide(firstNumber, secondNumber);
		std::cout << "Result: " << result;
		break;

	case 5: return 0;

	default: std::cout << "Option not valid.\n";
	}
    
    return 0;
}