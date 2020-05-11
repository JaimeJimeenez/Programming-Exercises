#include <iostream>

int main() {

	int mark;

	std::cout << "Write the mark of the alumn: ";
	std::cin >> mark;

	switch (mark)
	{
	case 4: std::cout << "Alumn: F\n";
		break;

	case 5: std::cout << "Alumn: E\n";
		break;

	case 7: std::cout << "Alumn: D\n";
		break;
		
	case 8: std::cout << "Alumn: B\n";
		break;
		
	case 9: std::cout << "Alumn: A\n";
		break;

	case 10: std::cout << "Alumn: A+\n";
		break;
	default:
		break;
	}

	return 0;
}

