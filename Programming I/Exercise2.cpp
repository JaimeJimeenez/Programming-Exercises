#include <iostream>
#include <string>

int main() {

    std::string sentence { "Tres tristes tigres comen trigo en un trigal.\n " };

    for (int i{ 0 }; i < sentence.size(); i++){
        if(sentence.find( "tri", i ) != -1 ){
            std::cout << "Found at: " << sentence.find( "tri", i ) << "\n";
            i = sentence.find( "tri", i );
        }
    }
    
    return 0;
}