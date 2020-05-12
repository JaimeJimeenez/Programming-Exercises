#include "Matrix.h"
#include <string>
#include <fstream>

Matrix::Matrix()
{
	this->rows = 3;
	this->columns = 3;
	data.resize(rows * columns, ' - ');
}

void Matrix::fillMatrix(std::string imputLine)
{
	char number;
	std::vector <char> characterVector;
	characterVector.resize(imputLine.size());

	for (int i{ 0 }; i < imputLine.size(); i++) {
		if (imputLine.at(i) == '-') imputLine.at(i) = '0';
		characterVector.at(i) = imputLine.at(i);
	}
	data = transformation(characterVector);
}

int Matrix::imputNumber()
{
	for (int i{ 1 }; i <= 9; i++) {
		for (int j{ 0 }; j < data.size(); j++) {
			if (i == data.at(j)) break;
			if (j == 8 && i != data.at(j)) return i;
		}
	}
	return 0;
}

void Matrix::solveMatrix()
{
	for (int i{ 0 }; i < data.size(); i++) {
		if (data.at(i) == 0) data.at(i) =  imputNumber();
	}
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getColumns() const
{
	return columns;
}

int Matrix::getElement(int row, int column)
{
	if (row >= rows || column >= columns) throw std::string{ "Error: Imput Parameter not valid.\n" };
	int position = row * columns + column;
	return data.at(position);
}

std::vector <int> Matrix::transformation(std::vector<char> imputVector)
{
	std::vector <int> returnVector;
	returnVector.resize(imputVector.size());

	for (int i{ 0 }; i < imputVector.size(); i++) {
		int number = imputVector.at(i) - '0';
		returnVector.at(i) = number;
	}
	
	return returnVector;
}

std::ostream& operator<<(std::ostream& out, Matrix& actualMatrix)
{
	for (int i{ 0 }; i < actualMatrix.getRows(); i++) {
		for (int j{ 0 }; j < actualMatrix.getColumns(); j++) {
			out << actualMatrix.getElement(i, j) << " ";
		}
		out << "\n";
	}
	return out;
}