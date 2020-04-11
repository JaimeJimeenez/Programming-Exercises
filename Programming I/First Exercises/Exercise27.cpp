#include <iostream>
#include <stdlib.h>
#include <array>
#include <set>

int main() {

    std::array <int, 20> imputArray;
    std::set <int> imputSet;

    for (int i { 0 }; i < imputArray.size(); i++) imputArray.at(i) = rand() % 101;

    for (auto elem : imputArray) imputSet.insert(elem);

    std::cout << "List: ";
    for (auto elem : imputSet) std::cout << elem << " - ";
    return 0;        
}