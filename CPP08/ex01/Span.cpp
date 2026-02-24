#include "Span.hpp"
#include <limits.h>

// Default constructor
Span::Span() : N(0)
{}

// Parameterized constructor
Span::Span(unsigned int capacity)
{
	if ((int)capacity < 0)
		throw (std::runtime_error("No a valid number"));
	N = capacity;
	vector.reserve(capacity);
	// if something -> bad_alloc ?
}

// Copy constructor
Span::Span(const Span &other)
{
	N = other.N;
	vector = other.vector;
}

// Copy assignment operator
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		vector = other.vector;
	}
	return (*this);
}

// Destructor
Span::~Span() {}

// Auxiliary functions

int Span::getMin()
{
	std::vector<int>::iterator smallest;
	smallest = std::min_element(vector.begin(), vector.end());
	return (*smallest);
}

int Span::getMax()
{
	std::vector<int>::iterator largest;
	largest = std::max_element(vector.begin(), vector.end());
	return (*largest);
}

bool Span::isLongEnough()
{
	if (vector.empty())
		throw (std::runtime_error("No span can be found in an empty array"));
	if (vector.size() == 1)
		throw (std::runtime_error("No span can be found in a single element array"));
	return (true);
}

// Public member functions

void Span::addNumber(int num)
{
	if (vector.size() == N )
		throw (std::runtime_error("Can't add a number beyond max capacity"));
	vector.push_back(num);
}

unsigned int Span::shortestSpan()
{
	isLongEnough();

	int shortest = INT_MAX;
	int diff = INT_MAX;
	std::vector<int> sorted_v = vector;
	std::sort(sorted_v.begin(), sorted_v.end());

	std::vector<int>::iterator it = sorted_v.begin();
	while(it != (sorted_v.end() - 1))
	{
		diff = *(it + 1) - *it;
		if (diff > 0)
		{
			shortest = (diff < shortest) ? diff : shortest;
			if (shortest == 1)
				break;
		}
		it++;
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	isLongEnough();
	return (getMax() - getMin());
}
