#include <iostream>
#include <vector>
#include <functional>

void showVector(std::vector <int> actualVector) {
	for (auto elem : actualVector) std::cout << elem << " - ";
}

std::function <void(int)> print = [](int actualElement) {
	std::cout << actualElement << " - ";
};

std::vector <int> onlyPars(std::vector <int> actualVector) {
	
	std::vector <int> returnVector;

	for (auto elem : actualVector) if (elem % 2 == 0) returnVector.push_back(elem);

	return returnVector;
}

void forEach(std::vector <int> actualVector, std::function <void(int)>& op) {
	for (auto elem : actualVector) op(elem);
};

std::function <bool(int)> isEven = [](int actualElement) {
	return (actualElement % 2 == 0);
};

std::vector <int> filter(std::vector <int> actualVector, std::function <bool(int)> op) {
	
	std::vector <int> returnVector;
	
	for (auto elem : actualVector) {
		if (op(elem)) returnVector.push_back(elem);
	}

	return returnVector;
}

std::vector <int> higher10(std::vector <int> actualVector) {
	
	std::vector <int> returnVector;

	for (auto elem : actualVector) if (elem > 10) returnVector.push_back(elem);

	return returnVector;
}

std::vector <int> multiplied2(std::vector <int> actualVector) {
	
	std::vector <int> returnVector;

	for (auto elem : actualVector) returnVector.push_back(2 * elem);

	return returnVector;
}

std::function <double(int)> operation = [](int actualElement) {
	return actualElement * 2;
};

std::vector <int> map(std::vector <int> actualVector, std::function <double(int)>& op) {
	
	std::vector <int> returnVector;

	for (auto elem : actualVector) returnVector.push_back(op(elem));

	return returnVector;
}

int main() {

	std::vector <int> imputVector{ 1, 3, 4, 13, 4, 6, 12, 7, 18 };

	forEach(imputVector, print);

	std::cout << "\n";

	std::vector <int> filteredVector = filter(imputVector, isEven);

	forEach(filteredVector, print);

	std::vector <int> newFilteredVector = filter(imputVector, [](int actualElement) {
		return (actualElement > 10);
		});

	std::cout << "\n";

	forEach(newFilteredVector, print);

	std::vector <int> anotherFiltered = map(imputVector, operation);

	std::cout << "\n";

	forEach(anotherFiltered, print);

	return 0;
}