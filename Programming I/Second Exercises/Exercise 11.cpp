#include <iostream>
#include <string>
#include <vector>
#include <functional>

struct Subjects {

	std::string subject;
	float mark;

};

struct Alumn {

	std::string name;
	std::string enrollment;
	std::vector <Subjects> alumnSubjects;
	Alumn* next;

};

Alumn* pushAlumn(Alumn* firstAlumn, Alumn* imputAlumn) {
	Alumn* actualAlumn{ firstAlumn };

	if (actualAlumn && imputAlumn) {
		while (actualAlumn->next) actualAlumn = actualAlumn->next;
		actualAlumn->next = imputAlumn;
	}
	else if (!firstAlumn) firstAlumn = imputAlumn;

	return firstAlumn;
}

void showVector(std::vector <Subjects> actualSubjects) {
	for (auto elem : actualSubjects) {
		std::cout << "Subject: " << elem.subject << "\n";
		std::cout << "Mark: " << elem.mark << "\n";
	}
}

std::function <void(Alumn*)> print = [](Alumn* actualAlumn) {

	std::cout << "Name: " << actualAlumn->name << "\n";
	std::cout << "Enrollment: " << actualAlumn->enrollment << "\n";
	showVector(actualAlumn->alumnSubjects); std::cout << "\n";
};

void forEach(Alumn* firstAlumn, std::function <void(Alumn*)> const& op) {

	Alumn* actualAlumn{ firstAlumn };
	while (actualAlumn) {
		op(actualAlumn);
		actualAlumn = actualAlumn->next;
	}

}

Alumn* pushEnrollment(Alumn* actualAlumn) {

	std::string imputSubject;
	float imputMark;

	std::cout << "Subject: ";
	std::cin >> imputSubject;
	std::cout << "Mark: ";
	std::cin >> imputMark;

	Subjects newSubject{ imputSubject, imputMark };
	actualAlumn->alumnSubjects.push_back(newSubject);

	return actualAlumn;
}

Alumn* deleteAlumn(Alumn* firstAlumn) {
	delete firstAlumn;
}

Alumn* putMark(Alumn* actualAlumn) {

	std::string searchSubject;
	float replaceMark;
	
	print(actualAlumn);

	std::cout << "What subject do you want to replace the mark?\n";
	std::cin >> searchSubject;

	for (auto elem : actualAlumn->alumnSubjects) {
		if (elem.subject == searchSubject) {
			std::cout << "New mark: ";
			std::cin >> replaceMark;
			elem.mark = replaceMark;
		}
	}
	
	return actualAlumn;
}

int main() {

	int option;

	Alumn* firstAlumn{ new Alumn { "Jaime", "bo0072", { { "Calculo", 7.3 } }, nullptr } };
	Alumn* secondAlumn{ new Alumn { "Rebeca", "jr2132", { { "Fisiopatologia", 8.5 } }, nullptr} };
	pushAlumn(firstAlumn, secondAlumn);

	Alumn* thirdAlumn{ new Alumn { "Jimmy", "jj9293", { }, nullptr } };

	std::cout << "1. Entry alumn.\n";
	std::cout << "2. Enrollment.\n";
	std::cout << "3. Unsuscribe.\n";
	std::cout << "4. Get mark of one of the subjects.\n";
	std::cout << "5. List proceedings.\n";
	std::cout << "6. Exit.\n";
	std::cin >> option;

	switch (option) 
	{
	case 1: pushAlumn(firstAlumn, thirdAlumn);
		break;

	case 2: pushEnrollment(thirdAlumn);
		break;

	case 3: deleteAlumn(firstAlumn);
		break;

	case 4: putMark(firstAlumn);
		break;

	case 5: forEach(firstAlumn, print);
		break;

	case 6:
		break;
	}
	forEach(firstAlumn, print);
	return 0;
}