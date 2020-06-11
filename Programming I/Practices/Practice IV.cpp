#include <iostream>
#include <vector>
#include <functional>

struct Bill {
	std::string date;
	float amount;
	Bill* next;
};

Bill* pushBill(Bill* firstBill, Bill* imputBill) {
	Bill* actualBill{ firstBill };
	if (actualBill != nullptr && imputBill != nullptr) {
		while (actualBill->next) actualBill = actualBill->next;
		actualBill->next = imputBill;
	}
	else if (firstBill == nullptr) firstBill = imputBill;
	return firstBill;
}

auto print = [](Bill* actualBill) -> void {
	std::cout << "Date: " << actualBill->date << "\n";
	std::cout << "Amount: " << actualBill->amount << "\n";
};

void forEach(Bill* firstBill, std::function <void(Bill*)> const & op) {
	Bill* actualBill{ firstBill };
	while (actualBill != nullptr) {
		op(actualBill);
		actualBill = actualBill->next;
	}
}

std::function <bool(Bill*)> isGreaterThan1000 = [](Bill* actualBill) {
	return (actualBill->amount > 1000);
};

Bill* filter(Bill* firstBill, std::function <bool(Bill*)> const& op) {
	Bill* returnFiltered{ nullptr };
	Bill* actualBill{ firstBill };
	
	while (actualBill) {
		if (op(actualBill)) returnFiltered = pushBill(returnFiltered, new Bill{actualBill->date, actualBill->amount, nullptr});
		actualBill = actualBill->next;
	}

	return returnFiltered;
}

int main() {

	Bill* firstBill{ new Bill{"20/04/1999", 200, nullptr} };
	Bill* secondBill{ new Bill{"25/10/1967", 2000, nullptr} };
	pushBill(firstBill, secondBill);
	Bill* thirdBill{ new Bill{"22/03/1999", 1500, nullptr} };
	pushBill(firstBill, thirdBill);
	forEach(firstBill, print);

	Bill* filteredBills{ filter(firstBill, isGreaterThan1000) };
	forEach(filteredBills, print);

	Bill* newFilteredBills{ filter(firstBill, [](Bill* actualBill) -> bool {
		return(actualBill->amount > 500);
		}) };
	forEach(newFilteredBills, print);

	return 0;
}