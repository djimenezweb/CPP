#include "PmergeMe.hpp"

void PmergeMe::initVector()
{
	std::string	str;

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		std::stringstream ss(str);
		int number;
		while (ss >> number)
			v.push_back(number);
	}
}

void PmergeMe::initList()
{
	std::string	str;

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		std::stringstream ss(str);
		int number;
		while (ss >> number)
			l.push_back(number);
	}
}

bool PmergeMe::isVectorSorted() const
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
			return (false);
	}
	return (true);
}

bool PmergeMe::isListSorted() const
{
	std::list<int>::const_iterator it = l.begin();
	std::list<int>::const_iterator it_next = it;
	std::advance(it_next, 1);
	std::list<int>::const_iterator it_end = l.end();
	while (it_next != it_end)
	{
		if (*it > *(it_next))
			return (false);
		std::advance(it, 1);
		if (it == it_end)
			break;
		it_next = it;
		std::advance(it_next, 1);
	}
	return (true);
}

void PmergeMe::printList(const std::list<int> &list) const
{
	std::list<int>::const_iterator it = list.begin();
	std::list<int>::const_iterator it_end = list.end();

	if (list.size() < 25)
	{
		while (it != it_end)
		{
			std::cout << *it << " ";
			std::advance(it, 1);
		}
	}
	else
	{
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << *it << " ";
			std::advance(it, 1);
		}
		std::cout << "[...] ";
		it = list.begin();
		std::advance(it, list.size() - 6);
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << *it << " ";
			std::advance(it, 1);
		}
	}
	std::cout << std::endl;
}

void PmergeMe::printVector(const std::vector<int> &vector) const
{
	if (vector.size() < 25)
	{
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
	}
	else
	{
		for (size_t i = 0; i < 6; i++)
			std::cout << vector[i] << " ";
		std::cout << "[...] ";
		for (size_t i = vector.size() - 6; i < vector.size(); i++)
			std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}
