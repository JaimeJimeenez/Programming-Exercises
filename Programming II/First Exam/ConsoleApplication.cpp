#include <iostream>

#include "List.h"

int main() {

	List <int> newList;
	newList.push_back(3);
	newList.push_back(4);

	std::cout << newList;
	return 0;
}
