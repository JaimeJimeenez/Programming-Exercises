#pragma once
#include <iostream>

class Person{
    friend std::ostream& operator<<(std::ostream&, const Person&);
public:

    Person(std::string, short int, std::string);

    void setName(const std::string&);
    std::string getName() const;

    void setAge(short int&);
    short int getAge() const;

    void setPhoneNumber(const std::string&);
    std::string getPhoneNumber() const;

private:

    std::string name;
    short int age;
    std::string phoneNumber;
    
};