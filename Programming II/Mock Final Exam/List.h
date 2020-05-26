#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include <vector>

template <class L>
class List
{
	template <typename L> friend std::ostream& operator<<(std::ostream&, const List<L>&);
public:

	List();

	void push_back(const L&);
	void push_front(const L&);
	void insertElement(const L&, unsigned long int);
	void deleteElement(unsigned long);

	L getData(unsigned long);

	unsigned long position(std::function <bool(L)>&op);

	List<L> filter(std::function <bool(L)>& op);

private:
	std::vector <L> data;
};

template<class L>
inline List<L>::List()
{
}

template<class L>
inline void List<L>::push_back(const L& imputValue)
{
	data.push_back(imputValue);
}

template<class L>
inline void List<L>::push_front(const L& imputValue)
{
	data.insert(data.begin(), imputValue);
}

template<class L>
inline void List<L>::insertElement(const L& imputValue, unsigned long int position)
{
	if (position >= data.size()) throw std::string{ "Error: Position not valid.\n" };
	data.insert(data.begin() + position, imputValue);
}

template<class L>
inline void List<L>::deleteElement(unsigned long position)
{
	if (position >= data.size()) throw std::string{ "Error: Position not valid.\n" };
	data.erase(data.begin() + position);
}

template<class L>
inline L List<L>::getData(unsigned long position)
{
	if (position >= data.size()) throw std::string{ "Error: Position not valid.\n " };
	return data.at(position);
}

template<class L>
inline unsigned long List<L>::position(std::function<bool(L)>& op)
{
	for (unsigned int i{ 0 }; i < data.size(); i++) {
		if (op(data.at(i))) return i;
	}
	return -1;
}

template<class L>
inline List <L> List<L>::filter(std::function<bool(L)>& op)
{
	List <L> result;

	for (auto elem : data) {
		if (op(elem)) result.push_back(elem);
	}

	return result;
}

template<typename L>
inline std::ostream& operator<<(std::ostream& out, const List<L>& actualList)
{
	out << "List:\n";
	for (unsigned int i{ 0 }; i < actualList.data.size(); i++) {
		out << *actualList.data.at(i);
	}
	return out;
}
