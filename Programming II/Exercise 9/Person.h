#pragma once
#include <iostream>

class Person
{
	friend std::ostream& operator<<(std::ostream&, const Person&);
public:

	Person(std::string, std::string, std::string, std::string);

	std::string getTypeOf() const;
	std::string getName() const;
	std::string getEmail() const;
	std::string getSubjects() const;

protected:
	std::string typeOf;
	std::string name;
	std::string email;
	std::string subjects;
};

