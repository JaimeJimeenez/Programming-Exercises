#include <iostream>
#include <vector>

void showVector(std::vector <int> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

bool isPrime(int number) {
    if (number == 1) return true;
    for (int i { 2 }; i < number; i++) {
        if (number % i == 0 && number != i) return false;
    }

    return true;
}

std::vector <int> primes(int number) {
    std::vector <int> returnVector;
    int i { 1 };
    int j { 0 };

    while (j < number) {
        if (isPrime(i)) {
            returnVector.push_back(i);
            i++;
            j++;
        }
        else i++;
    }

    return returnVector;
}

int main() {

    int number;

    std::cout << "Write a number: ";
    std::cin >> number;

    std::vector <int> onlyPrimes = primes(number);
    std::cout << "First " << number << " primes: ";
    showVector(onlyPrimes);

    return 0;
}