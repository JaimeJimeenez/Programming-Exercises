#include <iostream>
#include <vector>

void showVector (std::vector <int> actualVector) {
	for (auto elem : actualVector) std::cout << elem << " - ";
}

bool isPrime(int imputNumber) {

	if (imputNumber == 2) return true;
	for (int i{ 2 }; i < imputNumber; i++) if (imputNumber % i == 0) return false;
	return true;
}

int main() {

	int count;
	int initialCount{ 1 };
	std::vector <int> allPrimes;

	std::cout << "How many primes numbers do you want to calculate?";
	std::cin >> count;

	while (count > 0) {
		if (isPrime(initialCount)) {
			allPrimes.push_back(initialCount);
			initialCount++;
			count--;
		}
		else initialCount++;
	}

	showVector(allPrimes);
	return 0;
}