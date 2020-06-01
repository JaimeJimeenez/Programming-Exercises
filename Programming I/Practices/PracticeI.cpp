#include <iostream>
#include <string>

void hangman(int lifes) {
	switch (lifes)
	{
	case 6: std::cout << "  | \n";
		break;
	case 5: std::cout << "  | \n  O \n";
		break;
	case 4: std::cout << "  | \n  O \n  |";
		break;
	case 3: std::cout << "  | \n  O \n /| \n";
		break;
	case 2: std::cout << "  | \n  O \n /|/ \n";
		break;
	case 1: std::cout << "  | \n  O \n /|/ \n / \n";
		break;
	case 0: std::cout << "  | \n  O \n /|/ \n / / \n";
		break;
	default:
		break;
	}
}

int main() {

	unsigned int lifes{ 7 };
	char lettre;
	std::string keyWord;
	std::string imputWord;

	//Imput keyWord
	std::cout << "Keyword: ";
	std::cin >> keyWord;

	//Write the word with *
	imputWord.resize(keyWord.size(), '*');
	std::cout << imputWord << "\n";

	//Game
	while (lifes > 0) {

		std::cout << "Write a letter: ";
		std::cin >> lettre;
		if (keyWord.find(lettre) != -1) {
			int found = keyWord.find(lettre);
			imputWord.at(found) = lettre;
		}
		else {
			std::cout << "Error: Lettre not correct.\n";
			lifes--;
			hangman(lifes);
			std::cout << "\nLifes: " << lifes << "\n";
		}
		std::cout << imputWord << "\n";
		if (imputWord == keyWord) {
			std::cout << "You win!\n";
			return 0;
		}

	}
	return 0;
}