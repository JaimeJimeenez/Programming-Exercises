#include <iostream>
#include <vector>
#include <string>

int main() {

    std::vector <std::string> imputVector { "perro", "gato", "guardar", "andres", "luis", "guardar", "botella" };
    std::vector <std::string> saveVector;

    for (int i { 0 }; i < imputVector.size(); i++){
        if (imputVector.at(i) == "guardar") {
            for (int j { i + 1 }; j < imputVector.size(); j++) saveVector.push_back(imputVector.at(j));
        }
    }

    for (auto elem : saveVector) {
        std::cout << elem << ", ";
    }

    return 0;
}