#include <iostream>
#include <stdlib.h>
#include <vector>

void showVector(std::vector <int> actualVector) {
	for (auto elem : actualVector) std::cout << elem << " - ";
}

std::vector <int> generateVector() {

	std::vector <int> returnVector;
	unsigned int cant;
	int top;
	int bot;

	std::cout << "How many numbers do you want to generate?";
	std::cin >> cant;

	std::cout << "Parameters of that numbers: ";
	std::cin >> top >> bot;

	for (unsigned int i{ 0 }; i < cant; i++) {
		int random = rand() % bot + top;
		returnVector.push_back(random);
	}

	return returnVector;
}

float getMedia(std::vector <int> actualVector) {
	float result{ 0 };

	for (unsigned int i{ 0 }; i < actualVector.size(); i++) {
		result += actualVector.at(i);
	}

	return result/actualVector.size();
}

float getDesviation(std::vector <int> actualVector) {
	float result{ 0 };

	for (unsigned int i{ 0 }; i < actualVector.size(); i++) {
		result += actualVector.at(i) - getMedia(actualVector);
	}

	return sqrt(result / actualVector.size());
}

float getMedian(std::vector <int> actualVector) {

	float result{ 0 };

	if (actualVector.size() % 2 != 0) {
		result = actualVector.at(actualVector.size() / 2);
	}
	else {
		result = (actualVector.at(actualVector.size() / 2) + actualVector.at(actualVector.size() + 1)) / 2;
	}

	return result;
}

int main() {

	std::vector <int> randomNumbers = generateVector();

	
	int option;
	
	std::cout << "What do you want to do?\n";
	std::cout << "1.Media.\n";
	std::cout << "2.Typic desviation.\n";
	std::cout << "3.Median.\n";
	std::cout << "4.Generate a new vector number.\n";
	std::cout << "5.Exit.\n";
	std::cout << "Option: ";
	std::cin >> option;

	switch (option)
	{
	case 1:
		std::cout << "The media is " << getMedia(randomNumbers) << "\n";
		break;

	case 2:
		std::cout << "The typic desviation is " << getDesviation(randomNumbers) << "\n";
		break;

	case 3:
		std::cout << "The median is " << getMedian(randomNumbers) << "\n";
		break;

	case 4:
		std::vector <int> newVector = generateVector();
		break;

	case 5:
		break;

	default:
		break;
	} 

	return 0;
}