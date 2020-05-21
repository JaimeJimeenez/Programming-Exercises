#include "Alumn.h"

Alumn::Alumn(std::string name, std::string email, std::string subjects):Person("Alumn", name, email, subjects)
{
	this->name = name;
	this->email = email;
	this->subjects = subjects;
}

std::string Alumn::getName() const
{
	return name;
}

std::string Alumn::getEmail() const
{
	return email;
}

std::string Alumn::getSubjects() const
{
	return subjects;
}

std::string Alumn::getType() const
{
	return "Alumn";
}

std::ostream& operator<<(std::ostream& out, const Alumn& actualAlumn)
{

	out << "Alumn:\n";
	out << "Name: " << actualAlumn.getName() << "\n";
	out << "Email: " << actualAlumn.getEmail() << "\n";
	out << "Subjects: " << actualAlumn.getSubjects() << "\n";

	return out;
}
