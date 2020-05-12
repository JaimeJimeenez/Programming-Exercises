#include <iostream>
#include <fstream>

#include "Matrix.h"
#include "Sudoku.h"

int main() {

	std::ofstream newFile;

	newFile.open("Sudoku.txt");
	newFile << "--86-4---\n49-7-3---\n6--2----7\n-8---17-6\n2----85-4\n1--57-3-9\n86--1--4-\n----2--5-\n----58---";
	newFile.close();

	Sudoku newSudoku;
	newSudoku.rellenarSudoku();

	std::cout << newSudoku;
	return 0;
}