#include <iostream>

int main() {

	float a;
	float b;
	float c;

	std::cout << "Introduce the parameters a, b, c: ";
	std::cin >> a >> b >> c;

	float result = (-b + sqrt(pow(b, 2) - (4 * a * c))) / 2 * a;

	std::cout << "Result: " << result;

	return 0;
}