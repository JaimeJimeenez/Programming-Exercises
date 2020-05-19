#include <iostream>
#include <stdlib.h>
#include <array>
#include <set>

void showSet(std::set <int> actualSet) {
	for (auto elem : actualSet) std::cout << elem << " - ";
}

bool isPartOffibonacci(int imputNumber) {
	
	std::array <int, 20> fibonacci{ 0, 1 };

	for (int i{ 2 }; i < fibonacci.size(); i++) {
		fibonacci.at(i) = fibonacci.at(i - 1) + fibonacci.at(i - 2);
	}

	for (auto elem : fibonacci) {
		if (elem == imputNumber) return true;
	}

	return false;
}

std::set <int> filter(std::array <int, 100> imputArray) {

	std::set <int> returnSet;

	for (auto elem : imputArray) {
		if (isPartOffibonacci(elem)) returnSet.insert(elem);
	}

	return returnSet;
}

int main() {

	std::array <int, 100> saveNumbers;

	for (int i{ 0 }; i < saveNumbers.size(); i++) {
		int random = rand() % 500 + 1;
		saveNumbers.at(i) = random;
	}

	std::set <int> onlyFibonacci = filter(saveNumbers);
	std::cout << "Result:\n";
	showSet(onlyFibonacci);
	return 0;
}