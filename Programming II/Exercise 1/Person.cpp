#include "Person.h"

Person::Person(std::string name, short int age, std::string phoneNumber)
{
	this->name = name;
	this->age = age;
	this->phoneNumber = phoneNumber;
}

void Person::setName(std::string value)
{
	this->name = value;
}

std::string Person::getName()
{
	return name;
}

void Person::setAge(int value)
{
	if (value < 0 || value > 150) throw std::string{ "Error: Age not valid.\n" };
	this->age = value;
}

int Person::getAge()
{
	return age;
}

void Person::setPhoneNumber(std::string value)
{
	if (value.size() != 9) throw std::string{ "Error: Size of the phone number not valid.\n" };
	this->phoneNumber = value;
}

std::string Person::getPhoneNumber()
{
	return phoneNumber;
}

