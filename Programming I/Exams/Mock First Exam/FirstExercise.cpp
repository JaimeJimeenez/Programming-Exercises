#include <iostream>
#include <array>

void showArray(std::array <int, 20> actualArray) {
	std::cout << "Fibonacci sucession:\n";
	for (auto elem : actualArray) std::cout << elem << " - ";
}

std::array <int, 20> fibonacci() {

	std::array <int, 20> returnArray{ 0, 1 };

	for (int i{ 2 }; i < returnArray.size(); i++) {
		returnArray.at(i) = returnArray.at(i - 1) + returnArray.at(i - 2);
	}

	return returnArray;
}

int main() {

	std::array <int, 20> solution = fibonacci();
	showArray(solution);

	return 0;
}