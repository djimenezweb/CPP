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
	std::cout << "}" << std::endl;
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
	int unpaired = -1;
	if (vector.size() % 2 != 0)
	{
		unpaired = *it;
		// maxs.push_back(*it);
	}
	printSortedPairs(vector);
	printVector(maxs);
	printVector(mins);
	sort_by_pairs(maxs);

	// add the insertion logic after the recursive call

	// Build `chain` with first element from `mins` and all elements from `maxs`
	// First element from `mins` is paired with `maxs[0]`, so we already know it's <= maxs[0].
	std::vector<int> chain;
	chain.push_back(mins[0]);
	for (std::vector<int>::iterator maxs_it = maxs.begin(); maxs_it < maxs.end(); maxs_it++)
		chain.push_back(*maxs_it);
	// std::cout << "Chain: ";
	// printVector(chain);
	
	// Now add the rest of `mins` to chain. We already pushed mins[0] so we start by pushing mins[1], mins[2], etc.
	// However, we don't just push_back each element, we should insert it using binary search
	// That means iterating through chain???, find the insertion point and insert.
	for (std::vector<int>::iterator mins_it = mins.begin() + 1; mins_it < mins.end(); mins_it++)
	{
		for (std::vector<int>::iterator chain_it = chain.begin(); chain_it < chain.end(); chain_it++)
		{
			if (*mins_it >= *chain_it)
			{
				chain.insert(chain_it, *mins_it);
				break;
			}
		}
	};
	// And insert unpaired int if it exists using the same binary search:
	if (unpaired != -1)
	{
		for (std::vector<int>::iterator chain_it = chain.begin(); chain_it < chain.end(); chain_it++)
		{
			if (unpaired >= *chain_it)
			{
				chain.insert(chain_it, unpaired);
				break;
			}
		}
	}
	vector = chain;
	// std::cout << "Chain: ";
	// printVector(chain);
}

// Sort
void PmergeMe::sort()
{
	clock_t t1 = clock();

	printVector(v);
	sort_by_pairs(v);
	printVector(v);

	clock_t t2 = clock();
	std::cout << std::fixed << ((float)t2 - t1)/CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}
