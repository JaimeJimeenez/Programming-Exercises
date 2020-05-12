#pragma once
#include <iostream>
#include <vector>

#include "Matrix.h"

class Sudoku
{
	friend std::ostream& operator<<(std::ostream&, Sudoku&);
public:

	Sudoku();

	void rellenarSudoku();

private:

	std::vector <Matrix> data;

};

