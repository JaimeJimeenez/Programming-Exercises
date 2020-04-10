#include <iostream>
#include <vector> 

void showVector(std::vector <int> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

int main() {
    
    std::vector <int> fibonacciVector { 0, 1 };
    int number;

    std::cout << "Introduce one number: ";
    std::cin >> number;

    for (int i { 0 }; i < number; i++) {
        fibonacciVector.push_back(fibonacciVector.at(i) +  fibonacciVector.at(i + 1));
    }

    std::cout << "First " << number << " numbers of Fibonacci sucession: ";
    showVector(fibonacciVector);

    return 0;
}