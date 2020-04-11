#include <iostream>
#include <string>
#include <vector>

void showVector(std::vector <std::string> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

int main() {

    std::string sentence;
    std::vector <std::string> words;
    std::string word;

    std::cout << "Write a sentence: ";
    getline (std::cin, sentence);

    for (int i { 0 }; i < sentence.size(); i++) {
        if (sentence.at(i) == ' ' || i == sentence.size() - 1) {
            words.push_back(word);
            word.clear();
        }
        else word.push_back(sentence.at(i));
    }

    std::cout << "List of words: ";
    showVector(words);
    return 0;
}