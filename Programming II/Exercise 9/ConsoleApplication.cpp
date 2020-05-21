#include <iostream>
#include <memory>
#include <vector>

#include "List.h"
#include "Alumn.h"
#include "Professor.h"
#include "Person.h"

std::function <bool(const Alumn&, long)> searchEmail = [](const Alumn& actualAlumn, long index) {
	return (actualAlumn.getEmail() == "jaimejimenez99@hotmail.com");
};

int main() {

	try
	{

		//All Persons
		std::vector <std::unique_ptr<Person>> allLists;
		allLists.push_back(std::make_unique<Alumn>( "Jaime", "jaimejimenez99@hotmail.com", "Programming I, Programming II, Digital Systems" ));
		allLists.push_back(std::make_unique<Alumn>( "Jimmy", "jimmmydontknowhisemail@gmail.com", "Programming I, Maths" ));
		allLists.push_back(std::make_unique<Professor>( "Alberto", "dontknowhisemail@gmail.com", "Programming I, Programming II" ));
		allLists.push_back(std::make_unique<Professor>( "Alfonso", "dontknowhisemailatall@gmail.com", "Digital Systems" ));
		
		//List all
		for (const auto &elem : allLists) {
			std::cout << *elem;
		}

	}
	catch (const std::string& exception)
	{
		std::cout << exception;
	}
	return 0;
}