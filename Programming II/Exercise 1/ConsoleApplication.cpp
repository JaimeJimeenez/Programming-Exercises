#include <iostream>
#include "Person.h"
#include <functional>
#include <vector>

auto print = [](Person actualPerson) {
	std::cout << "Data:\n";
	std::cout << "Name: " << actualPerson.getName() << "\n";
	std::cout << "Age: " << actualPerson.getAge() << "\n";
	std::cout << "Telephone: " << actualPerson.getPhoneNumber() << "\n";
	std::cout << "------------------------------\n";
};

auto pushPerson = [](std::string name, short int age, std::string phoneNumber) -> Person{
	
	try
	{
		Person newPerson({ name, age, phoneNumber });

		return newPerson;
	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}
};

auto forEach = [](std::vector <Person> listPersons, std::function <void(Person)>const& op) {
	for (auto elem : listPersons) op(elem);
};

auto find = [](std::vector <Person> listPersons, std::function <bool(Person)>const& op) {
	for (auto elem : listPersons) if (op(elem)) return elem;
};

auto filter = [](std::vector <Person> listPerson, std::function <bool(Person)>const& op) {
	std::vector <Person> returnlist;
	for (auto elem : listPerson) if (op(elem)) returnlist.push_back(elem);
	return returnlist;
};

auto listByAge = [](std::vector <Person> listPerson, int age) {
	std::vector <Person> newList;

	for (auto elem : listPerson) {
		if (elem.getAge() == age) newList.push_back(elem);
	}

	return newList;
};

auto findByName = [](std::vector <Person> listPerson, const std::string& name) -> Person {
	for (auto elem : listPerson) {
		if (elem.getName() == name) return elem;
	}
};

int main() {

	std::vector <Person> listPersons;
	std::vector <Person> filterByAge;

	Person firstPerson = pushPerson("Jaime", 20, "123456789");
	listPersons.push_back(firstPerson);
	Person secondPerson("Lucia", 21, "987654321");
	listPersons.push_back(secondPerson);

	std::cout << "List all:\n";
	forEach(listPersons, print);

	filterByAge = listByAge(listPersons, 20);
	std::cout << "List by age (20):\n";
	forEach(filterByAge, print);

	Person filterByName = findByName(listPersons, "Jaime");

	return 0;
}
