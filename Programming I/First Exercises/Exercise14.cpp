#include <iostream>
#include <vector> 

void showVector(std::vector <int> imputVector){
    std::cout << "Par elements:\n";
    for(auto elem : imputVector) std::cout << elem << " - ";
}

int main() {

    std::vector <int> immputVector { 1, 3, 4, 5, 6, 7};
    std::vector <int> actualVector;

    for (auto elem : immputVector) {
        if (elem % 2 == 0) actualVector.push_back(elem);
    }
    std::cout << "Result: ";
    showVector(actualVector);

    return 0;
}
