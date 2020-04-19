#include "ListIn.h"

ListIn::~ListIn()
{
	for (auto elem : data) delete elem;
}

void ListIn::addPerson(Person* newPerson)
{
	if (newPerson) data.push_back(newPerson);
	else throw std::string{ "Error: Imput parameters of the person not valid.\n" };
}

void ListIn::forEach(std::function<void(Person*)> op) const
{
	for (auto elem : data) op(elem);
}

Person* ListIn::find(std::function<bool(Person*)> op) const
{
	for (auto elem : data) {
		if (op(elem)) return elem;
	}
	return nullptr;
}

ListIn ListIn::filter(std::function<bool(Person*)> op) const
{
	ListIn newList;
	for (auto elem : data) {
		if (op(elem)) newList.addPerson(elem);
	}
	return newList;
}
