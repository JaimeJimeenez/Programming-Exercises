#include <iostream>
#include <string>
#include <vector>

void showVector(std::vector <std::string> imputVector) {

	for (auto elem : imputVector) {
		std::cout << elem << " - ";
	}
}

int countLettre(std::string line, char imputLettre) {

	int cont{ 0 };

	for (int i{ 0 }; i < line.size(); i++) {
		if (line.at(i) == imputLettre) cont++;
	}

	return cont;
}

std::string reverse(std::string imputWord) {

	std::string result;
	int j{ 0 };

	result.resize(imputWord.size());

	for (int i = imputWord.size() - 1; i >= 0; i--) {
		result.at(j) = imputWord.at(i);
		j++;
	}
	return result;
}

std::vector <std::string> vectorWithoutLettre(std::string imputLine, char imputLettre) {

	std::vector <std::string> returnVector;
	std::string saveWord;

	for (int i{ 0 }; i < imputLine.size(); i++) {
		if (imputLine.at(i) != imputLettre) saveWord.push_back(imputLine.at(i));
		else returnVector.push_back(saveWord);
	}

	return returnVector;
}

int main() {

	std::string word;
	std::string line;
	char lettre;

	// 1
	std::cout << "Sentence: ";
	std::getline(std::cin, line);
	std::cout << "Lettre: ";
	std::cin >> lettre;
	int cont = countLettre(line, lettre);
	std::cout << cont << "\n";

	//2
	std::cout << "Imput word: ";
	std::cin >> word;
	std::string reverseWord = reverse(word);
	std::cout << reverseWord << "\n";

	//3
	std::string sentence;
	char character;
	std::cout << "Sentence: ";
	getline(std::cin, sentence);
	std::cout << "\nLettre: ";
	std::cin >> character;
	std::vector <std::string> actualVector = vectorWithoutLettre(sentence, character);
	showVector(actualVector);
	return 0;
}