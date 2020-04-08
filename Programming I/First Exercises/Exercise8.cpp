#include <iostream>
#include <string>
#include <vector>

int main() {

	std::vector <std::string> imputVector;
	std::string sentence;
	std::string word;

	std::cout << "Write a text: ";
	getline(std::cin, sentence);

	for (int i{ 0 }; i < sentence.size(); i++) {
		if (sentence.at(i) == ' ') {
			if (sentence.at(i + 1) == 'a') {
				word = sentence.substr(i, sentence.find(" ", i + 1));
				imputVector.push_back(word);
			}
		}
	}

	for (auto elem : imputVector) {
		std::cout << elem << ", ";
	}

	return 0;
}