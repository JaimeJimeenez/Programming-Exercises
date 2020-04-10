#include <iostream>
#include <stdlib.h>
#include <array> 
#include <set>

void showSet (std::set <int> actualSet) {
    for (auto elem : actualSet) std::cout << elem << " - ";
}

int main() {

    std::set <int> imputSet;
    std::array <int, 100> imputArray;

    for (int i { 0 }; i < 100; i++) {
        imputArray.at(i) = rand() % 20;
    }

    for (int i { 0 }; i < imputArray.size(); i++) {
        if (imputArray.at(i) % 3 == 0) imputSet.insert(imputArray.at(i));
    }

    showSet(imputSet);

    return 0;
}
