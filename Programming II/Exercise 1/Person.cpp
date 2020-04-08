#include "Person.h"

Person::Person(std::string name, short int age, std::string phoneNumber){
    if (age < 0 || age > 150) throw std::string { "Error: Imput age not valid.\n" };
    if (phoneNumber.size() != 9) throw std::string { "Error: Imput phone number not valid.\n"};
    this->name = name;
    this->age = age;
    this->phoneNumber = phoneNumber;
}

void Person::setName(const std::string& value){
    name = value;
}

std::string Person::getName() const{
    return name;
}

void Person::setAge(short int& value){
    if (value < 0 || value > 150) throw std::string { "Error: Imput age not valid.\n " };
    age = value;
}

short int Person::getAge() const{
    return age;
}

void Person::setPhoneNumber(const std::string& value){
    if (value.size() != 9) throw std::string { "Error: Imput phone number not valid.\n " };
    phoneNumber = value;
}

std::string Person::getPhoneNumber() const{
    return phoneNumber;
}

std::ostream& operator<<(std::ostream& out, const Person& actualPerson){
    out << "Data:\n";
    out << "Name: " << actualPerson.getName() << "\n";
    out << "Age: " << actualPerson.getAge() << "\n";
    out << "Phone Number: " << actualPerson.getPhoneNumber() << "\n";
    out << "---------------------------\n";
    return out;
}