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

void PmergeMe::sort_by_pairs(std::vector<int> &vector)
{
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator it_end = vector.end();
	while (it + 1 < it_end)
	{
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		it += 2;
	}
}

/* void PmergeMe::divide_by_pairs_rec(std::vector<int> parent)
{
	if (parent.size() <= 2)
		return;
	std::vector<int>::iterator it = parent.begin();
	std::vector<int>::iterator it_end = parent.end();
	std::vector<int>::iterator it_mid = parent.begin() + parent.size() / 2;

	std::vector<int> left(it, it_mid);
	std::vector<int> right(it_mid, it_end);

	std::cout << "{ ";
	printVector(left);
	std::cout << " }, { ";
	printVector(right);
	std::cout << " }" << std::endl;

	divide_by_pairs_rec(left);
	divide_by_pairs_rec(right);
} */

// Sort
void PmergeMe::sort()
{
	printVector(v);
	sort_by_pairs(v);
	printVector(v);
}
