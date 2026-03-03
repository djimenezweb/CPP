#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe() {}

// Parameterized constructor
PmergeMe::PmergeMe(int argc, char **argv) : argc(argc), argv(argv)
{}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
	// TO DO: Copy values
	(void)other;
}

// Copy assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		// TO DO: Copy values
	}
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe() {}

void PmergeMe::initVector()
{
	int					number;
	std::string			str;

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

void PmergeMe::printVector(std::vector<int> &vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << "}" << std::endl;
}

void PmergeMe::printSortedPairs(std::vector<int> &vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i % 2 != 0)
			std::cout << "\033[0m" << vector[i] << "\033[0m" << " ";
		else
			std::cout << "\033[33;1m" << vector[i] << "\033[0m" << " ";
	}
	std::cout << "}" << std::endl << std::endl;
}

void PmergeMe::sort_by_pairs(std::vector<int> &vector)
{
	if (vector.size() == 1)
	{
		printSortedPairs(vector);
		return;
	}
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator it_end = vector.end();
	std::vector<int> maxs;
	std::vector<int> mins;
	while (it + 1 < it_end)
	{
		if (*it > *(it + 1))
		{
			std::iter_swap(it, it + 1);
		}
		mins.push_back(*it);
		maxs.push_back(*(it + 1));
		it += 2;
	}
	if (vector.size() % 2 != 0)
		maxs.push_back(*it);
	printSortedPairs(vector);
	printVector(maxs);
	sort_by_pairs(maxs);
	// add the insertion logic after the recursive call
	std::vector<int> merged;
	merged.reserve(vector.size());
	merged.insert(merged.end(), maxs.begin(), maxs.end() );
	merged.insert(merged.end(), mins.begin(), mins.end() );
	printVector(merged);
	std::cout << "Merged size: " << merged.size() << std::endl;
}

// Sort
void PmergeMe::sort()
{
	std::cout << "Vector size: " << v.size() << std::endl;
	printVector(v);
	sort_by_pairs(v);
	// printVector(v);
}
