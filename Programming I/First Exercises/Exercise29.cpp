#include <iostream>
#include <vector>
#include <string>

void showVector(std::vector <std::string> actualVector) {
    for (auto elem : actualVector) std::cout << elem << " - ";
}

std::vector <std::string> words (std::string text, char keyWord) {
    std::vector <std::string> returnVector;
    std::string word;

    for (int i { 0 }; i < text.size(); i++) {
        if (text.at(i) == keyWord) {
            returnVector.push_back(word);
            word.clear();
        }
        else {
            word.push_back(text.at(i));
        }
    }

    return returnVector;
}

int main() {

    std::string sentence;
    char space;

    std::cout << "Write a sentence: ";
    getline(std::cin, sentence);
    std::cout << "Write a keyWord: ";
    std::cin >> space;

    std::vector <std::string> wordsWithoutKeyword = words(sentence, space);

    std::cout << "Result: ";
    showVector(wordsWithoutKeyword);
    return 0;
}