#pragma once
#include <iostream>
#include "Person.h"

class Alumn : public Person
{
	friend std::ostream& operator<<(std::ostream&, const Alumn&);
public:

	Alumn(std::string, std::string, std::string);

	std::string getName() const;
	std::string getEmail() const;
	std::string getSubjects() const;
	std::string getType() const;

private:
	std::string name;
	std::string email;
	std::string subjects;
};

