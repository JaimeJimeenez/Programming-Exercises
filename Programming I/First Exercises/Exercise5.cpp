#include <iostream>
#include <array>

int main() {

    std::array <int, 10> imputArray{1,2,3,4,5,6,7,8,9,10};

    for ( int i{0}; i < imputArray.size(); i++ ){
        if ( imputArray.at(i) == 7 ){
            std::cout << "Found at: " << i + 1;
            break;
        }
    }
    
    return 0;
}