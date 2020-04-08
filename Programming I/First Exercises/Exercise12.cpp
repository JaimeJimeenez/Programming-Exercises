#include <iostream>
#include <array>

int main() {

    std::array <int, 11> imputArray { 1, 2, 7, 7, 4, 3, 3, 7, 7, 7, 2 };
    int cont { 0 };
    int aux { 0 };

    for (int i { 0 }; i < imputArray.size(); i++) {
        if (imputArray.at(i) == 7){
            cont++;
            for (int j { i + 1 }; j < imputArray.size(); j++){
                if (imputArray.at(i) == imputArray.at(j)) cont++;
                else break;
            }
            if (cont > aux) aux = cont;
        }
        cont = 0;
    }
    std::cout << "Number of times that the number seven appeared in a row was " << aux;

    return 0;
}