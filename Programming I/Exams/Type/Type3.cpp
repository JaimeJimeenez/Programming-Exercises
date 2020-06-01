#include <iostream>
#include <vector>
#include <functional>

void showVectors(std::vector <int> actualVector) {
	for (auto elem : actualVector) std::cout << elem << " - ";
	std::cout << "\n";
}

std::vector <int> filter(std::vector <int> actualVector, std::function <bool(int)>op) {
	std::vector <int> returnVector;

	for (auto elem : actualVector) if (op(elem)) returnVector.push_back(elem);

	return returnVector;
}

int main() {

	std::vector <int> actualVector{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::vector <int> onlyPars = filter(actualVector, [](int actualNumber){
		return(actualNumber % 2 == 0);
		});

	showVectors(onlyPars);

	std::vector <int> onlyPrimes = filter(actualVector, [](int actualNumber) {
		if (actualNumber == 1) return true;
		for (int i{ 2 }; i < actualNumber; i++) {
			if (actualNumber % i == 0) return false;
		}
		return true;
		});

	showVectors(onlyPrimes);

	return 0;
}