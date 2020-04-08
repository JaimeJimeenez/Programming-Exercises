#include <iostream>
#include <vector>
#include <string>

int main() {

    std::string sentence;

    std::cout << "Write a text: ";
    getline(std::cin, sentence);
    for (int i { 0 }; i < sentence.size(); i++) {
        if (sentence.find('a') != - 1) {
            std::cout << sentence.substr(sentence.find('a'), sentence.size() - sentence.find(" "));
        }
    }

    return 0;
}
