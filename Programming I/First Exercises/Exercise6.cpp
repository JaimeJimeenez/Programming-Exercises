#include <iostream>
#include <array>

int main() {

    std::array <int, 10> imputArray{1,2,7,4,7,6,7,8,7,10};

    for ( int i{0}; i < imputArray.size(); i++ ){
        if ( imputArray.at(i) == 7 ) std::cout << "Found at: " << i + 1 << "\n";
    }
    
    return 0;
}