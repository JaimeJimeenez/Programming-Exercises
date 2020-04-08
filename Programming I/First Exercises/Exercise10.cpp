#include <iostream>
#include <array>

int main() {

    std::array <float, 10> imputArray { 8.43, 7.1, 9, 6, 10, 9, 8, 7.5, 7, 8 };
    float half { 0 };

    for (auto elem : imputArray) {
        half += elem;
    }
    std::cout << "The half is " << half/imputArray.size() << "\n";

    return 0;
}
