#include <iostream>

int main() {

    int number;
    int result { 0 };
    int i { 0 };

    std::cout << "Write a number: ";
    std::cin >> number;

    while (i <= number) {
        result += i;
        i++;
    }

    std::cout << "Sum = " << result << "\n";

    return 0;
}