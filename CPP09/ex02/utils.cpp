#include "PmergeMe.hpp"

void PmergeMe::initVector()
{
	int			number;
	std::string	str;

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		std::stringstream ss(str);
		while (!ss.eof())
		{
			ss >> number;
			if (ss.fail())
				return;
			v.push_back(number);
		}
	}
}

bool PmergeMe::isSorted()
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
			return (false);
	}
	return (true);
}

void PmergeMe::printVector(std::vector<int> &vector)
{
	if (vector.size() < 30)
	{
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
	}
	else
	{
		for (size_t i = 0; i < 10; i++)
			std::cout << vector[i] << " ";
		std::cout << ". . . ";
		for (size_t i = vector.size() - 10; i < vector.size(); i++)
			std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}
