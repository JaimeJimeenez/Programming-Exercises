#include <iostream>
#include <array>

void showVector(std::array <int, 10> imputArray){
    for (auto elem : imputArray) std::cout << elem << " - ";
}

int main() {

    std::array <int, 10> fibonacciArray { 0, 1 };

    for (int i { 0 }; i < fibonacciArray.size() - 2; i++){
        fibonacciArray.at(i + 2) = fibonacciArray.at(i) + fibonacciArray.at(i + 1);
    }
    std::cout << "First numbers of the Fibonacci Sucession: ";
    showVector(fibonacciArray);

    return 0;
}