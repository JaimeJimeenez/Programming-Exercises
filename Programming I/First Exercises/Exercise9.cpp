#include <iostream>
#include <array>

int main() {

    std::array <int, 10> imputArray { 3, 7, 5, 7, 8, 9, 10, 11, 7, 0 };
    int cont { 0 };

    for (auto elem : imputArray) {
        if (elem == 7) cont++;
    }
    std::cout << "Founded the number seven " << cont << " times.\n";

    return 0;
}