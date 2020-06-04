#include <iostream>

struct ComplexNumber{
    float realPart;
    float imaginePart;
};

ComplexNumber add(ComplexNumber const & firstComplex, ComplexNumber const & secondComplex) {
    ComplexNumber result;

    result.realPart = firstComplex.realPart + secondComplex.realPart;
    result.imaginePart = firstComplex.imaginePart + secondComplex.imaginePart;
    
    return result;
}

ComplexNumber substract(ComplexNumber const & firstComplex, ComplexNumber const &secondComplex) {
    ComplexNumber result;

    result.realPart = firstComplex.realPart - secondComplex.realPart;
    result.imaginePart = firstComplex.imaginePart - secondComplex.imaginePart;

    return result;
}

ComplexNumber multiply(ComplexNumber const & firstComplex, ComplexNumber const & secondComplex) {
    ComplexNumber result;

    result.realPart = firstComplex.realPart * secondComplex.realPart + firstComplex.imaginePart * secondComplex.imaginePart;
    result.imaginePart = firstComplex.realPart * secondComplex.imaginePart + firstComplex.imaginePart * secondComplex.realPart;

    return result;
}

void print(ComplexNumber const & imputComplex) {
    std::cout << imputComplex.realPart << " + i" << imputComplex.imaginePart << "\n";
}

int main() {

    ComplexNumber firstComplex { 2, 3 };
    ComplexNumber secondComplex { 3, 4 };

    ComplexNumber addResult{add(firstComplex, secondComplex)};
    ComplexNumber substractResult{substract(firstComplex, secondComplex)};
    ComplexNumber multiplyresult{multiply(firstComplex, secondComplex)};

    print(addResult);
    print(substractResult);
    print(multiplyresult);
    return 0;
}