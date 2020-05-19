#include <iostream>
#include <vector>
#include <functional>

auto showVector(std::vector <int> actualVector) -> void {

	for (auto elem : actualVector) std::cout << elem << " - ";
};

auto multiplyVector(std::vector <int> imputVector) -> std::vector <int> {
	std::vector <int> returnVector;

	for (auto elem : imputVector) {
		returnVector.push_back(elem * 2);
	}

	return returnVector;
};

auto multiplesOf3(std::vector <int> imputVector) -> std::vector <int> {
	std::vector <int> returnVector;

	for (int i{ 2 };  i < imputVector.size(); i++) {
		if (imputVector.at(i) % 3 == 0 && i % 2 == 0) returnVector.push_back(imputVector.at(i));
	}

	return returnVector;
};

int main() {


	std::vector <int> firstVector{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector <int> secondVector = multiplyVector(firstVector);
	std::cout << "First Vector asked:\n";
	showVector(secondVector);
	std::vector <int> thirdVector = multiplesOf3(firstVector);
	std::cout << "\nSecond Vector asked:\n";
	showVector(thirdVector);

	return 0;
}