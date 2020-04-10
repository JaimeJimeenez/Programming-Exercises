#include <iostream> 

bool isPrime(int number) {
    for (int i { 2 }; i < number; i++) {
        if (number % i == 0 && number != i) return false;
    }
    return true;
}

int main() {

    int number;

    std::cout << "Write a number: ";
    std::cin >> number;

    if(isPrime(10)) std::cout << "The number is prime.\n";
    else std::cout << "The number is not prime.\n";

    return 0;
}