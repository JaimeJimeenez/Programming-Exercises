#include <iostream>
#include <stdlib.h>
#include <vector>

void showVector (std::vector <int> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

bool isPrime(int number) {
    for (int i { 2 }; i < number; i++){
        if (number % i == 0 && number != i) return false;
    }
    return true;
}

std::vector <int> primesVector(std::vector <int> actualVector) {
    std::vector <int> returnVector;

    for (auto elem : actualVector) {
        if (isPrime(elem)) returnVector.push_back(elem);
    }

    return returnVector;
}

int main() {

    std::vector <int> imputVector;

    for (int i { 0 }; i < 20; i++) {
        imputVector.push_back(rand() % 20 + 1);
    }

    std::vector <int> onlyPrimes = primesVector(imputVector);
    showVector(onlyPrimes);

    return 0;
}