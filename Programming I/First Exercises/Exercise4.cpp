#include <iostream>
#include <string>

int main() {

    std::string imputSentence;
    std::string password;

    std::cout << "Write your password please: ";
    getline(std::cin, imputSentence);

    for (int i{ 0 }; i < imputSentence.size(); i++) {
        if (imputSentence.find("password") != -1) {
            password = imputSentence.substr(imputSentence.find("password") + 8, imputSentence.find(" ", imputSentence.find("password") + 1));
            std::cout << "Password founded: " << password;
            break;
        }
    }
    
    return 0;
}
