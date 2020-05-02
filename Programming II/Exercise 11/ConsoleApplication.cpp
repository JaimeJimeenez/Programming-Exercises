#include <iostream>
#include <vector>
#include <memory>

#include "Figure.h"
#include "Square.h"
#include "Triangle.h"
#include "Polygon.h"

int main() {

	try
	{
		float length;
		float height;

		std::vector <std::unique_ptr<Figure>> figureVector;

		//Square
		std::cout << "Imput paremeter for the Square: ";
		std::cin >> length;
		figureVector.push_back(std::make_unique <Square>(length));

		//Triangle
		std::cout << "Imput parameter for the Triangle (length and height): ";
		std::cin >> length;
		std::cin >> height;
		figureVector.push_back(std::make_unique <Triangle>(length, height));

		//Polygon
		int sides;
		std::cout << "Imput parameters for the Polygon (sides and length):";
		std::cin >> length;
		std::cin >> sides;
		figureVector.push_back(std::make_unique <Polygon>(sides, length));

		for (auto const& elem : figureVector) 
		{
			std::cout << elem->getTypeFigure() << "\n";
			std::cout << "Area: "  <<elem->getArea() << "\n";
			std::cout << "Perimeter: " << elem->getPerimeter() << "\n";
		}
	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}

	
	return 0;
}