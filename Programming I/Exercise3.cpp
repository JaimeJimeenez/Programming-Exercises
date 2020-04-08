#include <iostream>
#include <string>

int main() {

    std::string sentence { "En un lugar de la Mancha, de cuyo nombre no quiero acordarme.\n" };

    std::string firstPart = sentence.substr( 0, sentence.find( "Mancha") );
    std::string secondPart = sentence.substr( sentence.find( "Mancha" ) + 6, sentence.size() );
    std::cout << firstPart + secondPart << "\n";
    
    return 0;
}