#include <iostream>
#include <array> 

int main() {

    std::array <int, 10> imputArray { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
    int cont { 0 };
    int aux { 0 };
    int elem;

    for (int i { 0 }; i < imputArray.size(); i++) {
        for (int j { 0 }; j < imputArray.size(); j++){
            if (imputArray.at(i) == imputArray.at(j)) cont++;
        }
        if (cont > aux){
            aux = cont;
            elem = imputArray.at(i);
        } 
        cont = 0;
    }
    std::cout << "The number that appeared most was " << elem << ", " << aux << " times.\n";

    return 0;
}
