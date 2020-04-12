#pragma once
#include <iostream>

class Person
{
public:

	Person(std::string, short int, std::string);

	void setName(std::string);
	std::string getName();

	void setAge(int);
	int getAge();

	void setPhoneNumber(std::string);
	std::string getPhoneNumber();

private:
	std::string name;
	short int age;
	std::string phoneNumber;
};

