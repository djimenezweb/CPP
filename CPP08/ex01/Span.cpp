#include "Span.hpp"

// Default constructor
Span::Span() {}

// Copy constructor
Span::Span(const Span &other) {}

// Copy assignment operator
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
Span::~Span()
{
	// Delete allocated memory
}
