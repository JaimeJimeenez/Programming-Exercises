#include <iostream>
#include <vector>
#include <stdlib.h>

void showVector(std::vector <int> actualVector) {
	for (auto elem : actualVector) std::cout << elem << " - ";
}

std::vector <int> filter(std::vector <int> actualVector) {
	
	std::vector <int> returnVector;

	for (auto elem : actualVector)  if (elem % 5 == 0) returnVector.push_back(elem);

	return returnVector;
}

int main() {

	std::vector <int> imputVector;

	for (int i{ 0 }; i < 100; i++) {
		int random = rand() % 1001;
		imputVector.push_back(random);
	}

	std::vector <int> filteredVector = filter(imputVector);
	
    std::cout << "Initial Vector: ";
	showVector(imputVector);
	
    std::cout << "\nFiltered Vector: ";
	showVector(filteredVector);

	return 0;
}