#include <iostream>
#include <vector>

void showVectors(std::vector <int> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

std::vector <int> factors(int number) {
    std::vector <int> returnVector;

    for (int i { 1 }; i < number; i++) if (number % i == 0) returnVector.push_back(i);

    return returnVector;
}

int main() {

    int number;

    std::cout << "Write a number: ";
    std::cin >> number;

    std::vector <int> onlyFactors =  factors(number);
    std::cout << "Factors of that number: ";
    showVectors(onlyFactors);

    return 0;
}