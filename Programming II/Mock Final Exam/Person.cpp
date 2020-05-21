#include "Person.h"

Person::Person(std::string name, short int age)
{
	this->name = name;
	this->age = age;
}

std::string Person::getName() const
{
	return name;
}

short int Person::getAge() const
{
	return age;
}

std::ostream& operator<<(std::ostream& out, const Person& actualPerson)
{

	out << "Data:\n";
	out << "Name: " << actualPerson.getName() << "\n";
	out << "Age: " << actualPerson.getAge() << "\n";

	return out;
}