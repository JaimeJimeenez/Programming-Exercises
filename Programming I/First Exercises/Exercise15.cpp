#include <iostream>
#include <vector> 

void showVector(std::vector <int> imputVector) {
    std::cout << "Par elements:\n";
    for (auto elem : imputVector) std::cout << elem << " - ";
}

int main() {

    std::vector <int> imputVector { 1, 3, 4, 5, 6, 7 };
    std::vector <int> actualVector;
    int i { 0 };

    while (i < imputVector.size()) {
        if (imputVector.at(i) % 2 == 0) actualVector.push_back(imputVector.at(i)); 
        i++;
    }
    std::cout << "Result: ";
    showVector(actualVector);
    
    return 0;
}
