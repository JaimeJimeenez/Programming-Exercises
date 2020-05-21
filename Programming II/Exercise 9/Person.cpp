#include "Person.h"

Person::Person(std::string typeOf, std::string name, std::string email, std::string subjects)
{
	this->typeOf = typeOf;
	this->name = name;
	this->email = email;
	this->subjects = subjects;
}

std::string Person::getTypeOf() const
{
	return typeOf;
}

std::string Person::getName() const
{
	return name;
}

std::string Person::getEmail() const
{
	return email;
}

std::string Person::getSubjects() const
{
	return subjects;
}

std::ostream& operator<<(std::ostream& out, const Person& actualPerson)
{

	out << "Data:\n";
	out << "Type: " << actualPerson.getTypeOf() << "\n";
	out << "Name: " << actualPerson.getName() << "\n";
	out << "Email: " << actualPerson.getEmail() << "\n";
	out << "Subjects: " << actualPerson.getSubjects() << "\n";
	
	return out;
}
