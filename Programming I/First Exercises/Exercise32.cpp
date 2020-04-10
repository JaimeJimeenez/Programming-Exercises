#include <iostream>
#include <vector>

void showVector(std::vector <int> actualVector) {
    for(auto elem : actualVector) std::cout << elem << " - ";
}

std::vector <int> factors(int number) {
    std::vector <int> returnVector;
    int i { 2 };

    while (i <= number) {
        if (number % i == 0) {
            returnVector.push_back(i);
            number /= i;
        }
        else i++; 
    }
    return returnVector;
}

int main() {

    int number;

    std::cout << "Write a number: ";
    std::cin >> number;

    std::vector <int> onlyFactors = factors(number);
    showVector(onlyFactors);

    return 0;
}