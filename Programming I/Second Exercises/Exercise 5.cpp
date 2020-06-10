#include <iostream>

int main() {

	int imputNumber;
	int cont{ 0 };

	std::cout << "Imput the number: ";
	std::cin >> imputNumber;

	while (cont <= 10) {
		std::cout << "Result ( " << imputNumber << " * " << cont << " ): " << imputNumber * cont << "\n";
		cont++;
	}

	return 0;
}