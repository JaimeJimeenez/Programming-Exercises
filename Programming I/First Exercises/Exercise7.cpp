#include <iostream>
#include <string>

int main() {

    std::string text;
    int cont{ 0 };

    std::cout << "Write a text:";
    getline(std::cin, text);

    for (auto elem : text) {
        if (elem == 'a') cont++;
    }
    std::cout << "Found 'a' " << cont << " times.\n";
    
    return 0;
}