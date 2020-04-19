#pragma once

#include <vector>
#include <functional>
#include "Person.h"

class ListIn
{
	ListIn();
	~ListIn();

	void addPerson(Person*);
	void forEach(std::function <void(Person*)>) const;

	Person* find(std::function<bool(Person*)>) const;
	ListIn filter(std::function<bool(Person*)>) const;

private:
	std::vector<Person*> data;
};

