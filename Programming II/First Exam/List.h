#pragma once

#include <iostream>
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

	List<L> map(std::function <void(const L&, long)>&);
	L* find(std::function <bool(const L&, long)>&);
	List<L> filter(std::function <bool(const L&, long)>&);

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
inline void List<L>::forEach(std::function<void(const L&, long index)>& op)
{
	for (int i{ 0 }; i < data.size(); i++) op(data.at(i));
}

template<class L>
inline List<L> List<L>::map(std::function<void(const L&, long index)>& op)
{
	List<L> returnList;
	for (int i{ 0 }; i <= data.size(); i++) returnList.push_back(op(data.at(i)));
}

template<class L>
inline L* List<L>::find(std::function<bool(const L&, long index)>& op)
{
	for (int i{ 0 }; i < data.size(); i++) {
		if (op(data.at(i))) return data.at(i);
	}
	throw std::string{ "Error: Value not found.\n" };
}

template<class L>
inline List<L> List<L>::filter(std::function<bool(const L&, long index)>&)
{
	List<L> returnList;

	for (int i{ 0 }; i <= data.size(); i++) {
		if (op(data.at(i))) returnList.push_back(data.at(i));
	}

	return returnList;
}

template<typename L>
inline std::ostream& operator<<(std::ostream& out, const List<L>& actualList)
{
	for (int i{ 0 }; i < actualList.data.size(); i++) {
		out << actualList.data.at(i) << "\n";
	}
	return out;
}
