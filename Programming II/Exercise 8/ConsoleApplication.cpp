#include <iostream>

#include "Figure.h"
#include "EquilateralTriangle.h"
#include "Square.h"
#include "Polygon.h"


int main() {

	try
	{
		float length;

		//Equilateral Triangle
		std::cout << "Imput length for the Triangle.\n";
		std::cin >> length;
		EquilateralTriangle newTriangle(length);
		std::cout << "Figure: " << newTriangle.getTypeFigure() << "\n";
		std::cout << "Area: " << newTriangle.getArea() << "\n";
		std::cout << "Perimeter: " << newTriangle.getPerimeter() << "\n";
		std::cout << "------------------------------------------\n";

		//Square
		std::cout << "Imput length for the Square.\n";
		std::cin >> length;
		Square newSquare(length);
		std::cout << "Figure: " << newSquare.getTypeFigure() << "\n";
		std::cout << "Area: " << newSquare.getArea() << "\n";
		std::cout << "Perimeter: " << newSquare.getPerimeter() << "\n";
		std::cout << "--------------------------------------\n";

		//Polygon
		int sides;
		std::cout << "Imput length and sides for the Polygon.\n";
		std::cin >> length >> sides;
		Polygon newPolygon(sides, length);
		std::cout << "Figure: " << newPolygon.getTypeFigure() << "\n";
		std::cout << "Area: " << newPolygon.getArea() << "\n";
		std::cout << "Perimeter: " << newPolygon.getPerimeter() << "\n";
	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}
	return 0;
}