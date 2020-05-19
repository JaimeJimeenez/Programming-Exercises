#include <iostream>
#include <string>
#include <vector>

void showAllWords(std::vector <std::string> actualVector) {
	std::cout << "Words:\n";
	for (auto elem : actualVector) std::cout << elem << " - ";
}

bool reviewWord(std::string imputWord) {

	int contA{ 0 };

	for (int i{ 0 }; i < imputWord.size(); i++) {
		if (imputWord.at(i) == 'a') contA++;
	}

	if (contA > 1) return true;
	return false;
}

int main() {

	std::vector <std::string> result;
	std::string line;
	std::string word;

	std::cout << "Write a sentence:";
	std::getline(std::cin, line);

	for (int i{ 0 }; i < line.size(); i++) {
		if (line.at(i) != ' ' ) word.push_back(line.at(i));
		else {
			if (reviewWord(word)) result.push_back(word);
			word.erase();
		}
	}

	showAllWords(result);

	return 0;
}