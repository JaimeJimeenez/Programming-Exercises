#include <iostream>
#include <vector>
#include <functional>

struct Book {
	std::string author;
	std::string title;
	std::vector <std::string> tags;
	std::string location;
	long int index;
	Book* next;
};

void printVector(std::vector <std::string> imputVector) {
	for (auto elem : imputVector) std::cout << elem << " - ";
}

Book* pushBook(Book* firstBook, Book* newBook) {
	Book* actualBook{ firstBook };
	
	if (actualBook && newBook) {
		while (actualBook->next) actualBook = actualBook->next;
		actualBook->next = newBook;
	}
	else if (!firstBook) firstBook = newBook;

	return firstBook;
}

Book* deleteBook(Book* firstBook, Book* deletedBook) {
	Book* resultBook{ firstBook };

	while (resultBook) {
		if (deletedBook == resultBook) delete deletedBook; break;
		resultBook = resultBook->next;
	}

	return resultBook;
}

std::function <void(Book*)> print = [](Book* actualBook) {
	std::cout << "Author: " << actualBook->author << "\n";
	std::cout << "Title: " << actualBook->title << "\n";
	std::cout << "Tags: "; printVector(actualBook->tags); std::cout << "\n";
	std::cout << "Location: " << actualBook->location << "\n";
	std::cout << "Index: " << actualBook->index << "\n";
};

void forEach(Book* firstBook, std::function <void(Book*)> const& op) {
	Book* actualBook{ firstBook };
	while (actualBook) {
		op(actualBook);
		actualBook = actualBook->next;
	}
}

Book* searchTags(Book* firstBook) {
	std::string keyWord;
	Book* actualBook{ firstBook };
	
	std::cout << "Write key words to find the book: ";
	std::cin >> keyWord;
	while (actualBook) {
		for (auto elem : actualBook->tags) if (elem == keyWord) return actualBook;
		actualBook = actualBook->next;
	}

	return nullptr;
}

Book* searchTitle(Book* firstBook) {
	std::string keyWord;
	Book* actualBook{ firstBook };

	std::cout << "Write key words to find the book: ";
	std::cin >> keyWord;
	while (actualBook) {
		if (keyWord == actualBook->title) return actualBook;
		actualBook = actualBook->next; 
	}

	return nullptr;
}

Book* searchAuthor(Book* firstBook) {
	std::string keyWord;
	Book* actualBook{ firstBook };

	std::cout << "Write key words to find the book: ";
	std::cin >> keyWord;
	while (actualBook) {
		if (keyWord == actualBook->author) return actualBook;
		actualBook = actualBook->next;
	}

	return nullptr;
}

Book* search(Book* firstBook) {

	int option;

	std::cout << "How do you want to find the book?\n";
	std::cout << "1.By one of the tags.\n";
	std::cout << "2.By title.\n";
	std::cout << "3.By author.\n";
	std::cin >> option;
	switch (option)
	{
	case 1: return searchTags (firstBook);
		break;

	case 2: return searchTitle(firstBook);
		break;

	case 3: return searchAuthor(firstBook);
		break;
	default: std::cout << "Error: Option not valid.\n";
		break;
	}
	
	return nullptr;
}

Book* modifyBook(Book* firstBook) {
	return nullptr;
}

int main() {

	int option;

	Book* firstBook{ new Book{"Edgar Allan Poe", "Filosofia de la composicion", { "Poems" , "Litherature" }, "Boston", 20000} };
	Book* secondBook{ new Book{"Gabriel Garcia Marquez", "Cien años de soledad", { "Litherature"}, "España", 20001} };
	pushBook(firstBook, secondBook);
	forEach(firstBook, print);

	Book* thirdBook{ new Book{"Miguel de Cervantes", "Don Quijote de la Mancha", { "Litherature"}, "España", 20010} };

	std::cout << "1. Push book.\n";
	std::cout << "2. Delete book.\n";
	std::cout << "3. List all books.\n";
	std::cout << "4. Modified book.\n";
	std::cout << "5. Search book.\n";
	std::cout << "Option: ";
	std::cin >> option;

	switch (option)
	{
	case 1: pushBook(firstBook, thirdBook);
		break;

	case 2: deleteBook(firstBook, secondBook);
		break;

	case 3: forEach(firstBook, print);
		break;

	case 4: Book * modifyBook(firstBook);
		break;

	case 5: Book * foundBook{ search(firstBook) };
		  print(foundBook);
		break;
	}
	return 0;
}