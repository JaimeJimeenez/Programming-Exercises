#include <fstream>
#include <string>

#include "Matrix.h"
#include "Sudoku.h"

Sudoku::Sudoku()
{
}

void Sudoku::rellenarSudoku()
{
	std::fstream enterFile;

	std::string name;
	std::string line;

	std::cout << "File name: ";
	std::cin >> name;

	enterFile.open(name.c_str(), std::ios::in);
	if (enterFile.is_open()) {

		while (!enterFile.eof()) {
			std::getline(enterFile, line);
			Matrix newMatrix;
			newMatrix.fillMatrix(line);
			data.push_back(newMatrix);
		}
	}
}

std::ostream& operator<<(std::ostream& out, Sudoku& actualSudoku)
{
	
	return out;
}
