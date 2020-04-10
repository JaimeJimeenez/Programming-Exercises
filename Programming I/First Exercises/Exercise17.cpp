#include <iostream>
#include <vector>

void showVector(std::vector <int> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

int main() {

    int a, b, c;
    int result;
    std::vector <int> imputVector;

    std::cout << "Write three numbers in order: ";
    std::cin >> a >> b >> c;

    for (int i { 0 }; i < b / 2; i++) {
        result = c * i;
        if(result >= a && result <= b) imputVector.push_back(result);
    }
    std::cout << "Result:\n";
    showVector(imputVector);

    return 0;
}