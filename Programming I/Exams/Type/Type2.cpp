#include <iostream>
#include <vector>

void showVector(const std::vector <int>& actualVector) {
	for (auto elem : actualVector) std::cout << elem << " - ";
}

bool isPrime(int& imputNumber) {
	
	for (int i{ 2 }; i < imputNumber; i++) {
		if (imputNumber % i == 0) return false;
	}
	return true;
}

std::vector <int> allPrimes(int& imputNumber) {

	std::vector <int> returnVector;

	for (int i{ 2 }; i < imputNumber; i++) {
		if (isPrime(i)) returnVector.push_back(i);
	}

	return returnVector;
}

std::vector <int> onlyFactors(std::vector <int> actualVector, int imputNumber) {
	std::vector <int> returnVector;
	
	for (auto elem : actualVector) {
		if (imputNumber % elem == 0) {
			returnVector.push_back(elem);
			imputNumber /= elem;
		}
	}

	return returnVector;
}

int main() {

	int imputNumber;

	std::cout << "Imput number: ";
	std::cin >> imputNumber;

	std::vector <int> onlyPrimes = allPrimes(imputNumber);
	std::vector <int> factors = onlyFactors(onlyPrimes, imputNumber);
	showVector(factors);
	return 0;
}