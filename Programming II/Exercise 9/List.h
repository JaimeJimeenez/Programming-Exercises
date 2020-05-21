#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>

template <class L>
class List
{
	template <typename L> friend std::ostream& operator<<(std::ostream&, const List<L>&);
public:

	List();

	void push_back(const L&);
	void forEach(std::function <void(const L&, long)>&);

	L find(std::function <bool(const L&, long)>&);
	
	std::vector <L> filter(std::function <bool(const L&, long)>&);
	std::vector <L> map(std::function <void(const L&, long)>&);

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
inline void List<L>::forEach(std::function<void(const L&, long)>&op)
{
	for (int i{ 0 }; i < data.size(); i++) op(data.at(i), i);
}

template<class L>
inline L List<L>::find(std::function<bool(const L&, long)>&op)
{
	for (int i{ 0 }; i < data.size(); i++) {
		if (op(data.at(i), i)) return data.at(i);
	}
	throw std::string{ "Error: Element not found.\n" };
}

template<class L>
inline std::vector<L> List<L>::filter(std::function<bool(const L&, long)>&op)
{
	std::vector <L> result;

	for (int i{ 0 }; i < data.size(); i++) {
		if (op(data.at(i), i)) result.push_back(data.at(i));
	}
}

template<class L>
inline std::vector<L> List<L>::map(std::function<void(const L&, long)>&op)
{
	std::vector <L> result;

	for (int i{ 0 }; i < data.size(); i++) {
		result.push_back(op(data.at(i), i));
	}

	return result;
}

template<typename L>
inline std::ostream& operator<<(std::ostream& out, const List<L>& actualList)
{
	out << "Data:\n";
	for (int i{ 0 }; i < actualList.data.size(); i++) out << actualList.data.at(i) << "\n";
	
	return out;
}
