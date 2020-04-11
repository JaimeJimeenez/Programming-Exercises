#include <iostream>

bool isPrime(int number) {
    int i { 2 };

    if (number <= 1) return true;
    while (i <= number) {
        if (number % i == 0) return false;
        i++;
    }
    return true;
}

int main() {

    int number;
    int i { 2 }; 

    std::cout << "Write a number: ";
    std::cin >> number;

    if (isPrime(number)) std::cout << "The number is prime.\n";
    else std::cout << "The number is not prime.\n";
    
    return 0;
}