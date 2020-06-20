#include <iostream>
#include <functional>

struct Car {

	std::string enrollment;
	std::string model;
	std::string timeIn;
	std::string timeOut;
	std::string ubication;
	Car* next;

};

std::function <void(Car*)> print = [](Car* actualCar) {
	std::cout << "Enrollment: " << actualCar->enrollment << "\n";
	std::cout << "Model: " << actualCar->model << "\n";
	std::cout << "Time in: " << actualCar->timeIn << "\n";
	std::cout << "Time out: " << actualCar->timeOut << "\n";
	std::cout << "Ubication: " << actualCar->ubication << "\n";
};

void forEach(Car* firstCar, std::function <void(Car*)> const& op) {
	Car* actualCar{ firstCar };

	while (actualCar) {
		op(actualCar);
		actualCar = actualCar->next;
	}

}

Car* pushCar(Car* firstCar, Car* imputCar) {
	Car* actualCar{ firstCar };

	if (actualCar && imputCar) {
		while (actualCar->next) actualCar = actualCar->next;
		actualCar->next = imputCar;
	}
	else if (!firstCar) firstCar = imputCar;

	return firstCar;
}

Car* searchByEnroll(Car* firstCar) {

	Car* actualCar{ firstCar };
	std::string imputEnrollment;

	std::cout << "Write the enrollment.\n";
	std::cin >> imputEnrollment;

	while (actualCar) {
		if (actualCar->enrollment == imputEnrollment) return actualCar;
		actualCar = actualCar->next;
	}

	return nullptr;
}

Car* searchByModel(Car* firstCar) {

	Car* actualCar{ firstCar };
	std::string imputModel;

	std::cout << "Write the model.\n";
	std::cin >> imputModel;

	while (actualCar) {
		if (actualCar->model == imputModel) return actualCar;
		actualCar = actualCar->next;
	}
	std::cout << "Car not found.\n";
	return nullptr;
}

Car* search(Car* firstCar) {

	int option;

	std::cout << "How do you want to search the car?\n";
	std::cout << "1. By enrollment.\n";
	std::cout << "2. By model.\n";

	std::cin >> option;
	switch (option)
	{
	case 1: return searchByEnroll(firstCar);
		break;

	case 2: return searchByModel(firstCar);
		break;
	}

	return nullptr;
}

bool validyTicket(Car* firstCar) {

	Car* foundCar{ search(firstCar) };
	int totaltoPay{ 0 };

	//Time Out
	
	//Time in
	return true;
}

Car* deleteCar(Car* firstCar) {
	Car* actualCar{ firstCar };

	while (!validyTicket(actualCar)) std::cout << "Ticket not valid.\n";

	delete actualCar;

	return firstCar;
}

int main() {

	int option;

	Car* firstCar { new Car { "8984GSK", "Mercedes", "08:30", "12:00", "Principe Pio", nullptr } };
	Car* secondCar{ new Car { "8292JCK", "Seat", "19:00", "24:00", "Las Rozas", nullptr} };

	std::cout << "1. Push car.\n";
	std::cout << "2. List parking.\n";
	std::cout << "3. Search car.\n";
	std::cout << "4. Validy ticket.\n";
	std::cout << "5. Unsuscribed car.\n";
	std::cin >> option;

	switch (option)
	{
	case 1: pushCar(firstCar, secondCar);
		break;
		
	case 2: forEach(firstCar, print);
		break;

	case 3: print(search(firstCar));
		break;

	case 4: validyTicket(firstCar);
		break;

	case 5: deleteCar(firstCar);
		break;

	default:
		break;
	}

	return 0;
}