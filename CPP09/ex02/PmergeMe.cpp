#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe() {}

// Parameterized constructor
PmergeMe::PmergeMe(int argc, char **argv) : argc(argc), argv(argv)
{}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other) : argc(other.argc), argv(other.argv), v(other.v), l(other.l)
{}

// Copy assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		argc = other.argc;
		argv = other.argv;
		v = other.v;
		l = other.l;
	}
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe() {}

void printStats(std::string str, size_t size, double t)
{
	std::cout << "Time to process a range of "
			  << size << " elements with " << str << " : "
			  << std::fixed << std::setprecision(6) << t
			  << " s" << std::endl;
}

void PmergeMe::sort()
{
	clock_t t_start = clock();
	initVector();
	std::cout << "Before:  ";
	printVector(v);
	sortVector(v);
	clock_t t_vector = clock() - t_start;
	
	t_start = clock();
	initList();
	sortList(l);
	clock_t t_list = clock() - t_start;

	std::cout << " After:  ";
	printVector(v);

	printStats("std::vector<int>", v.size(), static_cast<double>(t_vector)/CLOCKS_PER_SEC);
	printStats("std::list<int>  ", l.size(), static_cast<double>(t_list)/CLOCKS_PER_SEC);
}
