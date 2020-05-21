#include <iostream>
#include <memory>
#include <functional>

#include "Person.h"
#include "List.h"

std::function <bool(std::shared_ptr<Person>)> filterOperation = [](std::shared_ptr<Person> actualPerson) {
	return (actualPerson->getAge() < 25);
};

std::function <bool(std::shared_ptr<Person>)> findOperation = [](std::shared_ptr<Person> actualPerson) {
	return (actualPerson->getName() == "Jaime");
};

int main() {
	
	try
	{
		List<std::shared_ptr<Person>>newList;

		newList.push_back(std::make_shared <Person>("Jaime", 21));
		newList.push_front(std::make_shared <Person>("Lucia", 21));
		newList.insertElement(std::make_shared <Person>("Marcos", 25), 0);
		std::cout << newList << "\n";
		newList.deleteElement(1);
		std::cout << newList << "\n";
		auto positionPerson = newList.getData(0);
		std::cout << *positionPerson;

		int found = newList.position(findOperation);
		if (found != -1) std::cout << "Value found at " << found << "\n";
		else std::cout << "Value not found\n";

		List <std::shared_ptr<Person>> filteredList;
		filteredList = newList.filter(filterOperation);
		std::cout << filteredList;

	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}
	return 0;
}