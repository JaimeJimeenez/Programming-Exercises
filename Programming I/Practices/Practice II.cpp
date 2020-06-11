#include <iostream>
#include <vector>

void printBoard(std::vector <int> actualVector) {
	int rows { 5 };
	int columns { 5 };
	
	for (int i{ 0 }; i < rows; i++) {
		for (int j{ 0 }; j < columns; j++) {
			int position = i * columns + j;
			std::cout << actualVector.at(position) << " ";
		}
		std::cout << "\n";
	}

}

bool checkFileColumn(int imputFile) {
	return (imputFile > 5 || imputFile < 0);
}

int pushFile(int imputColumn, std::vector <int> actualBoard) {
	for (int i{ 4 }; i >= 0; i--) {
		int position = i * 5 + imputColumn;
		if (actualBoard.at(position) == 0) return position;
	}
	return -1;
}

bool checkColumn(std::vector <int> actualBoard) {

	int cont{ 0 };

	for (int i{ 0 }; i < 5; i++) {
		for (int j{ 0 }; j < 5; j++) {
			int position = i * 5 + j;
			if (position % 4 != 0) {
				if (actualBoard.at(position) == actualBoard.at(position + 1) && actualBoard.at(position) != 0) cont++;
				else break;
			}
		}
	}

	if (cont > 4) return true;
	
	return false;
}

bool checkRow(std::vector <int> actualBoard) {
	
	int cont{ 0 };

	for (int i{ 0 }; i < 5; i++) {
		for (int j{ 0 }; j < 5; j++) {
			int position = j * 5 + i;
			if (position % 4 != 0) {
				if (actualBoard.at(position) == actualBoard.at(position + 1) && actualBoard.at(position) != 0) cont++;
				else break;
			}
		}
	}

	if (cont > 3) return true;

	return false;
}

int main() {

	std::vector <int> board;
	int imputFile;
	int contTurns{ 0 };

	//Initial board
	board.resize(25, 0);
	std::cout << "Initial Board:\n"; 
	printBoard(board);

	while (contTurns < 25) {

		//1st Player
		std::cout << "Select column (1 - 5): ";
		std::cin >> imputFile;
		while (checkFileColumn(imputFile)) {
			std::cout << "Error: Column not found.\n Try again: ";
			std::cin >> imputFile;
		}
		imputFile = imputFile - 1;
		
		contTurns++;

		while (pushFile(imputFile, board) == -1) {
			std::cout << "Error: Full column.\nTry again: ";
			std::cin >> imputFile;
			while (checkFileColumn(imputFile)) {
				std::cout << "Error: Column not found.\n Try again: ";
				std::cin >> imputFile;
			}
			imputFile = imputFile - 1;
		}
		board.at(pushFile(imputFile, board)) = 1;

		//Show board
		printBoard(board);

		if (checkColumn(board)) std::cout << "Column achieved.\n";
		if (checkRow(board)) std::cout << "Row achieved.\n";

		//2nd Player
		std::cout << "Select column (1 - 5): ";
		std::cin >> imputFile;
		while (checkFileColumn(imputFile)) {
			std::cout << "Error: Column not found.\n Try again: ";
			std::cin >> imputFile;
		}
		imputFile = imputFile - 1;

		contTurns++;

		while (pushFile(imputFile, board) == -1) {
			std::cout << "Error: Full column.\nTry again: ";
			std::cin >> imputFile;
			while (checkFileColumn(imputFile)) {
				std::cout << "Error: Column not found.\n Try again: ";
				std::cin >> imputFile;
			}
			imputFile = imputFile - 1;
		}
		board.at(pushFile(imputFile, board)) = 2;

		//Show board
		printBoard(board);

		if (checkColumn(board)) std::cout << "Column achieved.\n";
		if (checkRow(board)) std::cout << "Row achieved.\n";

	}
	
	return 0;
}