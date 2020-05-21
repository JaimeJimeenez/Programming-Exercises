#pragma once
#include <iostream>

class Person
{
	friend std::ostream& operator<<(std::ostream&, const Person&);
public:

	Person(std::string, short int);

	std::string getName() const;
	short int getAge() const;

private:
	std::string name;
	short int age;
};

