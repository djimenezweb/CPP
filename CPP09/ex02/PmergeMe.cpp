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

void printStats(std::string str, size_t size, double t, bool sorted)
{
	std::cout << std::left
			  << std::setw(18) << str
			  << std::setw(12) << size
			  << std::setw(12) << std::fixed << std::setprecision(7) << t
			  << std::setw(12) << std::boolalpha << sorted
			  << std::endl;
}

void PmergeMe::sort()
{
	
	std::cout << "Before:  ";
	clock_t t1 = clock();
	initVector();
	printVector(v);
	sortVector(v);
	clock_t t2 = clock();
	std::cout << " After:  ";
	printVector(v);

	std::cout << "Before:  ";
	clock_t t3 = clock();
	initList();
	printList(l);
	sortList(l);
	clock_t t4 = clock();
	std::cout << " After:  ";
	printList(l);

	std::cout << std::left
			  << std::setw(18) << "Container"
			  << std::setw(12) << "Elements"
			  << std::setw(13) << "Time (µs)" // sec, ms, µs ???
			  << std::setw(12) << "Sorted"
			  << std::endl;
	printStats("std::vector<int>", v.size(), static_cast<double>(t2 - t1)/CLOCKS_PER_SEC, isVectorSorted());
	printStats("std::list<int>", l.size(), static_cast<double>(t4 - t3)/CLOCKS_PER_SEC, isListSorted());
}
