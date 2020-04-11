#include <iostream>
#include <string>
#include <vector>

void showVectors(std::vector <std::string> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

std::vector <std::string> imputWords(std::string text) {
    std::string word;
    std::vector <std::string> words;

    for (int i { 0 }; i < text.size(); i++) {
        if (text.at(i) == ' ' || i == text.size() - 1) {
            words.push_back(word);
            word.clear();
        }
        else word.push_back(text.at(i));
    }

    return words;
}

int main() {

    std::vector <std::string> words;
    std::string sentence;

    std::cout << "Write a sentence: ";
    getline (std::cin, sentence);

    std::cout << "Words: ";
    showVectors(words);
    return 0;
}