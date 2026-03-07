#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe() {}

// Parameterized constructor
PmergeMe::PmergeMe(int argc, char **argv) : argc(argc), argv(argv)
{
	initVector();
}

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

void PmergeMe::sort()
{
	
	std::cout << "Before:  ";
	printVector(v);

	clock_t t1 = clock();
	sortVector(v);
	clock_t t2 = clock();

	clock_t t3 = clock();
	sortVector(v);
	clock_t t4 = clock();

	std::cout << " After:  ";
	printVector(v);

	std::cout << std::left
			  << std::setw(18) << "Container"
			  << std::setw(12) << "Elements"
			  << std::setw(13) << "Time (µs)" // sec, ms, µs ???
			  << std::setw(12) << "Sorted"
			  << std::endl;
	std::cout << std::left
			  << std::setw(18) << "std::vector<int>"
			  << std::setw(12) << v.size()
			  << std::setw(12) << std::fixed << std::setprecision(7) << static_cast<double>(t2 - t1)/CLOCKS_PER_SEC
			  << std::setw(12) << std::boolalpha << isSorted()
			  << std::endl;
	std::cout << std::left
			  << std::setw(18) << "(other)"
			  << std::setw(12) << v.size()
			  << std::setw(12) << std::fixed << std::setprecision(7) << static_cast<double>(t4 - t3)/CLOCKS_PER_SEC
			  << std::setw(12) << std::boolalpha << isSorted()
			  << std::endl;
}
