#include "Professor.h"

Professor::Professor(std::string name, std::string email, std::string subjects):Person("Professor", name, email, subjects)
{
	this->name = name;
	this->email = email;
	this->subjects = subjects;
}

std::string Professor::getName() const
{
	return name;
}

std::string Professor::getEmail() const
{
	return email;
}

std::string Professor::getSubjects() const
{
	return subjects;
}

std::string Professor::getType() const
{
	return "Professor";
}

std::ostream& operator<<(std::ostream& out, const Professor& actualProfessor)
{

	out << "Professor:\n";
	out << "Name: " << actualProfessor.getName() << "\n";
	out << "Email: " << actualProfessor.getEmail() << "\n";
	out << "Subjects: " << actualProfessor.getSubjects() << "\n";

	return out;
}
