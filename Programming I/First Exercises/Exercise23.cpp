#include <iostream>

int main() {

    int number;
    int result { 1 };

    std::cout << "Write a number: ";
    //std::cin >> number;

    for (int i { number }; i > 0; i--) {
        result *= i;
    }

    std::cout << "The factorial is " << result;

    return 0;
}