#include <iostream>

struct ComplexNumber {
	float realPart;
	float imaginePart;
};

void print(ComplexNumber actualComplex) {
	std::cout << "Actual Complex Number: " << actualComplex.realPart << " + " << actualComplex.imaginePart << "i.\n";
}

ComplexNumber add(ComplexNumber firstComplex, ComplexNumber secondComplex) {
	ComplexNumber result;

	result.realPart = firstComplex.realPart + secondComplex.realPart;
	result.imaginePart = firstComplex.imaginePart + secondComplex.imaginePart;

	return result;
}

ComplexNumber substract(ComplexNumber firstComplex, ComplexNumber secondComplex) {
	ComplexNumber result;

	result.realPart = firstComplex.realPart - secondComplex.realPart;
	result.imaginePart = firstComplex.imaginePart - secondComplex.imaginePart;

	return result;
}

ComplexNumber multiply(ComplexNumber firstComplex, ComplexNumber secondComplex) {
	ComplexNumber result;

	result.realPart = firstComplex.realPart * secondComplex.realPart;
	result.imaginePart = firstComplex.imaginePart * secondComplex.imaginePart;

	return result;
}

int main() {

	ComplexNumber firstComplex{ 1, 2 };
	ComplexNumber secondComplex{ 3, 4 };

	print(firstComplex);
	print(secondComplex);

	ComplexNumber resultAdd = add(firstComplex, secondComplex);
	ComplexNumber resultSubstract = substract(firstComplex, secondComplex);
	ComplexNumber resultMultiply = multiply(firstComplex, secondComplex);
	
	print(resultAdd);
	print(resultSubstract);
	print(resultMultiply);

	return 0;
}